#include "..\inc\atmega2560.h"
#include "..\inc\hw_timer.h"
#include "drvcore.h"

/* delay in milliseconds */
const UINT8 DELAY = 100;

/* wrapper for writing register */
void drvWriteReg(UINT16 base, UINT16 offset, UINT8 value)
{
	*((volatile UINT16 *)(base + (offset*ADDR_MULTIPLIER))) = value;
}

/* wrapper for writing register */
UINT8 drvReadReg(UINT16 base, UINT16 offset)
{
	return *((volatile UINT16 *)(base + (offset*ADDR_MULTIPLIER)));
}


void timer_init(UINT8 delay) { 

    /* global interrupt disable */
    cli();

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

void timer_interrupt() {
    static UINT8 pin;
	static UINT8 on;

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
    volatile UINT8 data_received;

    /* Set the Data Register Empty flag */
    data_received = drvReadReg(USART0_BASEADDR,USART_UDR_OFFSET);
	/* put it in the queue */
    if(!RingBuffer_IsFull(&rbuff))
	    RingBuffer_Insert(&rbuff,data_received);


	sei();
}

void init_usart0() 
{

    volatile UINT8 string[] = "Hello World\r\n";
    volatile UINT8 val = 0;

	val = USART_RX_EN | USART_TX_EN | USART_RX_COMP_IE;
    drvWriteReg(USART0_BASEADDR,USART_UCSRB_OFFSET,val);

	val = USART_8_DATA_BITS;
    drvWriteReg(USART0_BASEADDR,USART_UCSRC_OFFSET,val);

    /* calculate baud rate based on cpu frequency */
	val = ((F_CPU + 9600 * 8L) / (9600 * 16L) - 1);

    /* write baud rate register */
   	drvWriteUint16Reg(USART0_BASEADDR,USART_UBRR_OFFSET,val);

    /* send I'm alive message */
	drvUSARTWriteString((UINT8 *)string, sizeof(string));
}

void drvUSARTWriteString(const UINT8 * data,UINT8 length)
{
	while(*data != '\0')
	    drvUSARTPutChar(*data++);
}
 
void drvUSARTPutChar(UINT8 data) {
    while((drvReadReg(USART0_BASEADDR,USART_UCSRA_OFFSET) & USART_DATA_REG_EMPTY) 
	        != USART_DATA_REG_EMPTY) { ; }
	drvWriteReg(USART0_BASEADDR,USART_UDR_OFFSET,data);

}

/**
  * Get the number of bytes currently written to eprom and 
  * set pointer to next address available for writing.
  */
void init_eeprom() {

    number_of_bytes_used_in_eeprom = (drvReadEeprom(EEPROM_DATA_COUNT_ADDR)<<8);
    number_of_bytes_used_in_eeprom |= drvReadEeprom(EEPROM_DATA_COUNT_ADDR+1);
	if ( number_of_bytes_used_in_eeprom == 0xFF ) 
        number_of_bytes_used_in_eeprom = 0;
	next_eeprom_address = number_of_bytes_used_in_eeprom + 1;

}


/* do we have to manage a buffer here in case the eeprom is not ready? */
void drvWriteEeprom(UINT16 addr, UINT8 data)
{
    /* Wait for completion of previous write */
    /*while(EECR & (1<<EEPE))*/
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & EEPROM_PRG_EN)
    ;

    /* Set up address and Data Registers */
    /*EEAR = uiAddress;*/
	drvWriteUint16Reg(EEPROM_BASE,EEPROM_ADDR_OFFSET,addr);

    /*EEDR = ucData;*/
    drvWriteReg(EEPROM_BASE,EEPROM_DATA_OFFSET,data);

    /* Write logical one to EEMPE */
    /*EECR |= (1<<EEMPE);*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_MSTR_PRG_EN);

    /* Start eeprom write by setting EEPE */
    /*EECR |= (1<<EEPE);*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_PRG_EN);
    
}

UINT8 drvReadEeprom(UINT16 addr) {

    /* Wait for completion of previous write */
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & EEPROM_PRG_EN)
    ;
    /* Set up address register */
    /*EEAR = uiAddress;*/
	drvWriteUint16Reg(EEPROM_BASE,EEPROM_ADDR_OFFSET,addr);

    /* Start eeprom read by writing EERE */
    /*EECR |= (1<<EERE);*/
    /*eeprom_control_reg = drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) | EEPROM_READ_EN;*/
    drvWriteReg(EEPROM_BASE,EEPROM_CTRL_OFFSET,EEPROM_READ_EN);

    /* Return data from Data Register */
    return drvReadReg(EEPROM_BASE,EEPROM_DATA_OFFSET);

}

void drvUpdateEepromDataCount() {

    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR, (next_eeprom_address>>8));
    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR+1, (next_eeprom_address&0xFF));
	next_eeprom_address++;
}

void drvResetEepromDataCount() {

    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR, 0);
    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR+1, 0);

	number_of_bytes_used_in_eeprom = 0;
	next_eeprom_address = EEPROM_DATA_START_ADDR;
}


void init_gpio(UINT16 port) {
 /* set portb for output to LEDs */
 drvWriteReg(DRV_PORTB,DRV_GPIO_PORT_OFFSET , 0xFF);
 /* set portd for input from switches */
 drvWriteReg(DRV_PORTD,DRV_GPIO_PORT_OFFSET , 0x00);
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

