#include "..\inc\atmega2560.h"
#include "..\inc\hw_timer.h"
#include "drvcore.h"

UINT8 hit_it = 0;
volatile UINT16 next_eeprom_address;
volatile UINT8 number_of_bytes_used_in_eeprom;

/* wrapper for writing register */
void drvWriteReg(UINT16 base, UINT16 offset, UINT8 value)
{
	*((volatile UINT8 *)(base + (offset*ADDR_MULTIPLIER))) = value;
}

/* wrapper for writing register */
UINT8 drvReadReg(UINT16 base, UINT16 offset)
{
	return *((volatile UINT8 *)(base + (offset*ADDR_MULTIPLIER)));
}

/* delay in milliseconds */
const UINT8 DELAY = 100;

/* flag used by ISR to indicate timout to main function */
volatile UINT8 timeout;

void timer_init(UINT8 delay) { 

    /* global interrupt disable */
    cli();

    /* reset timeout flag */
    timeout = 0;

    /* set pre-scaler to F_CPU/1024 */
    HWREG(TCCR0B) |= TC0_CK_1024;
    
    /* Program the timer with the value you want 
    which is (256-the number of counts) into TCNT0. */ 
    HWREG(TCNT0) = 256-delay; 

    /* Enable Overflow Interrupt for Counter 0 */
    HWREG(TIMSK0) = TOIE0; 

    /* Enable Global Interrupts */ 
    sei();

}


/* This function simply sets up the timer and loops until */
/* the timers rolls over.                                 */
void delay(int ms) {

    /* set up timer */
	timer_init(ms);

    /* wait for interrupt flag */
	while (!timeout) {
	;
	}

    return;
}

/* This function simply sets up the timer and loops until */
/* the timers rolls over.                                 */
void delay_mSec() {

    /* set up timer */
	timer_init(100);

    /* wait for interrupt flag */
	while (!timeout) {
	;
	}

    return;
}

void timer_interrupt() {
    static UINT8 pin;
	static UINT8 on;

	/* set some flag variable */
    timeout = 1;

    /* reset the timer */
    HWREG(TCNT0) = 256-DELAY; 
	    
	toggle_pin(DRV_PORTB+DRV_GPIO_PORT_OFFSET,pin);
	/* increment to next pin after toggle on/off once. */
	if ( pin < 8 ) {
	    if ( on<1 ) {
			on++;
        } else {
   	        pin += 1;
			on = 0;
        /* if the operator is pressing the current button then
	       reset the count */
            if ( drvTestBit(DRV_PORTD,DRV_GPIO_PIN_OFFSET,pin) )
	            pin = 0;
        }
    }
    else 
	    pin = 0;

}

/* in you port.c code */
/* timer 0 overflow interrupt service routine */
void __vector_23 (void) 
{ 

	/* set some flag variable */
    timer_interrupt();
	sei();
}


/**
 * USART0 RX Complete ISR 
 * Read the USART data register.
 * If ctl-Z set record to eeprom flag
 */
void __vector_25 (void) 
{ 
    static UINT8 record_to_eeprom;
    volatile UINT8 data_received;
	volatile UINT8 i;

    /* Set the Data Register Empty flag */
    data_received = drvReadReg(USART0_BASEADDR,USART_UDR_OFFSET);
	if (data_received == RECORDING_CONTROL_CHAR) {
	    /* if currently recording then stop else start recording */
	    if(!record_to_eeprom)
	        record_to_eeprom = TRUE;
        else
		    record_to_eeprom = FALSE;
    } else if (data_received == PLAYBACK_CHAR)  {
			for(i = 1;i < next_eeprom_address;i++)
	            drvWriteReg(USART0_BASEADDR,USART_UDR_OFFSET,drvReadEeprom(i));
	} else if (record_to_eeprom) {
	        drvWriteReg(USART0_BASEADDR,USART_UDR_OFFSET,data_received);

            drvWriteEeprom(next_eeprom_address, data_received);
    }


	sei();
}

/**
 * USART0 Data Register Empty ISR 
 */
void __vector_26 (void) 
{ 

}

/**
 * USART0 TX Complete ISR 
 */
void __vector_27 (void) 
{ 

}



DRVCTRL example;

/* set direction */
void init_port(UINT8 port_id) {

	DRVGPIO gpio = example.gpio;


}

void toggle_pin(UINT16 port, UINT8 pin) {

	/* set port for output */
	HWREG(port-1) |= 1<<pin; 


	HWREG(port) ^= 1<<pin;
}


void write_pin(UINT16 port, UINT8 pin, UINT8 value) {

	/* set port for output */
	HWREG(port-1) |= 1<<pin; 

    if (value)
	/* output to port */
        HWREG(port) |= (1<<pin); 
    else
	    HWREG(port) &= (UINT8)~(1<<pin);
}


UINT8 read_pin(UINT16 port, UINT8 pin) {

	/* set port for input */
	HWREG(port-1) &= (UINT8)~pin; 

	return(HWREG(port-2) &= pin);

}
	    

DRVUSART serial_port;
void drv_usart_init(DRVUSART serial_port, UINT16 baseaddr, UINT16 baudrate, UINT8 stop_bits, UINT8 date_bits, UINT8 partiy)
{

    serial_port.baseaddr = baseaddr;
    DRVUSARTCTRL ctrl = serial_port.control;
	ctrl.baud_rate = baudrate;



}

/*((F_CPU + UART_BAUD_RATE * 8L) / (UART_BAUD_RATE * 16L) - 1)*/

void init_usart0() 
{

    volatile UINT8 string[] = "hello world";
    volatile UINT8 val = 0;
	volatile UINT8 pointer;
	volatile UINT8 empty;

	val = USART_RX_EN | USART_TX_EN | USART_RX_COMP_IE;
    drvWriteReg(USART0_BASEADDR,USART_UCSRB_OFFSET,val);

	val = USART_8_DATA_BITS;
    drvWriteReg(USART0_BASEADDR,USART_UCSRC_OFFSET,val);

    /* F_CPU=1MHz Baud Rate 9600 */
	val = ((F_CPU + 9600 * 8L) / (9600 * 16L) - 1);

    drvWriteReg(USART0_BASEADDR,USART_UBRRH_OFFSET,(UINT8)(val>>8));
    drvWriteReg(USART0_BASEADDR,USART_UBRRL_OFFSET,(UINT8)(val&0xFF));

	for (pointer=0;pointer < 12;pointer++) {
	    empty = drvReadReg(USART0_BASEADDR,USART_UCSRA_OFFSET);
		empty &= USART_DATA_REG_EMPTY;
        while(empty != USART_DATA_REG_EMPTY) {
			empty = drvReadReg(USART0_BASEADDR,USART_UCSRA_OFFSET);
		    empty &= USART_DATA_REG_EMPTY;
        }
	    drvWriteReg(USART0_BASEADDR,USART_UDR_OFFSET,string[pointer]);

    }
}

void init_gpio(UINT16 port) {
 drvWriteReg(DRV_PORTB,DRV_GPIO_PORT_OFFSET , 0xFF);
 drvWriteReg(DRV_PORTD,DRV_GPIO_PORT_OFFSET , 0x00);


}

/* do we have to manage a buffer here in case the eeprom is not ready? */
void drvWriteEeprom(UINT16 addr, UINT8 data)
{

    /* Wait for completion of previous write */
    /*while(EECR & (1<<EEPE))*/
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & (EEPROM_PRG_EN))
    ;

    /* Set up address and Data Registers */
    /*EEAR = uiAddress;*/
    drvWriteReg(EEPROM_BASE,EEPROM_ADDR_HI_OFFSET,addr>>8);
    drvWriteReg(EEPROM_BASE,EEPROM_ADDR_LO_OFFSET,(UINT8)(addr&0xFF));

    /*EEDR = ucData;*/
    drvWriteReg(EEPROM_BASE,EEPROM_DATA_OFFSET,data);

    /* Write logical one to EEMPE */
    /*EECR |= (1<<EEMPE);*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_MSTR_PRG_EN);

    /* Start eeprom write by setting EEPE */
    /*EECR |= (1<<EEPE);*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_PRG_EN);
    
	next_eeprom_address++;
}

UINT8 drvReadEeprom(UINT16 addr) {

    volatile UINT8 eeprom_control_reg;

    /* Wait for completion of previous write */
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & (EEPROM_PRG_EN))
    ;
    /* Set up address register */
    /*EEAR = uiAddress;*/
    drvWriteReg(EEPROM_BASE,EEPROM_ADDR_HI_OFFSET,addr>>8);
    drvWriteReg(EEPROM_BASE,EEPROM_ADDR_LO_OFFSET,(UINT8)(addr&0xFF));

    /* Start eeprom read by writing EERE */
    /*EECR |= (1<<EERE);*/
    /*eeprom_control_reg = drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) | EEPROM_READ_EN;*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_READ_EN);

    /* Return data from Data Register */
    return drvReadReg(EEPROM_BASE,EEPROM_DATA_OFFSET);
    /*EEDR;*/

}

/**
  * Used to set a bit in a in a given byte at a given address.
  */
void drvSetBit(UINT16 addr, UINT8 position)
{;
}

/**
  * Used to clear a bit in a in a given byte at a given address.
  */
void drvClearBit(UINT16 addr,UINT8 position){;}


/**
  * Used to test a bit in a in a given byte at a given address.
  */
UINT8 drvTestBit(UINT16 addr, UINT16 offset, UINT8 position) {
    volatile UINT8 value;
    value = (UINT8)~drvReadReg(addr,offset) & (1<<position);
    return( value >> position);
}

/**
  * Get the number of bytes currently written to eprom and 
  * set pointer to next address available for writing.
  */
UINT16 init_eeprom() {


    number_of_bytes_used_in_eeprom = drvReadEeprom(0);
	if ( number_of_bytes_used_in_eeprom == 0xFF ) 
        number_of_bytes_used_in_eeprom = 0;
	next_eeprom_address = number_of_bytes_used_in_eeprom + 1;

}
