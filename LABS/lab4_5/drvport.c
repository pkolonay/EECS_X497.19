/*****************************************************************************/
/* Filename: drvport.c                                                       */
/* Description: Code for  Lab4/5 of ECS_X497.19.                             */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
#include "..\inc\atmega2560.h"
#include "..\inc\hw_timer.h"
#include "drvcore.h"

/** Next address to which data can be written in the EEPROM. */
volatile UINT16 next_eeprom_address;
/** Holds the number of bytes that have been written to the EEPROM. */
volatile INT16  number_of_bytes_used_in_eeprom;

/* delay in milliseconds */
const UINT8 DELAY = 100;

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


/** Initialize TIMER0 to generate an operflow insterrupt */
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


/** Interrupt handler for TIMER0 */
void timer_interrupt() {
    /** Current pin that is being turned on/off */
    static UINT8 pin;
	/** Current state of pin. Used to toggle */
	static UINT8 on;

    /* reset the timer counter*/
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
    /** Keeps track of if the data received should be written to the EEPROM */
    static   UINT8 record_to_eeprom;
	/** Holds latest data received on the serial port */
    volatile UINT8 data_received;
	volatile UINT8 i;
	/** Used to create string for number of bytes in EEPROM output. For a 4 
	  *  digit ascii string to output the number of bytes in the eeprom */
	volatile UINT8 myascii[5]; 
	/** Holds the latest value read from the EEPROM bytes used location. */
	volatile UINT16 number_of_bytes_in_eeprom;

    data_received = drvReadReg(USART0_BASEADDR,USART_UDR_OFFSET);
	if (data_received == RECORDING_CONTROL_CHAR) {
	    /* if currently recording then stop else, start recording! */
	    if(!record_to_eeprom) {
			/* reset character count and pointers*/
			drvResetEepromDataCount();
	        record_to_eeprom = TRUE;
        } else {
		    record_to_eeprom = FALSE;
        }
    } else if (data_received == PLAYBACK_CHAR)  {
			for(i = EEPROM_DATA_START_ADDR;i < next_eeprom_address;i++)
	            drvUSARTPutChar(drvReadEeprom(i));
    } else if (data_received == DUMP_NUMBER_OF_BYTES_CHAR) {
	            /* initialize array */
	            drvUSARTWriteString((UINT8 *)BYTES_STORED_STRING,sizeof(BYTES_STORED_STRING));
				/* initialize string */
				myascii[0]='\0';
				/* read the write count from eeprom and convert to ascii */
				number_of_bytes_in_eeprom = drvRead16Eeprom(EEPROM_DATA_COUNT_ADDR);
				if (number_of_bytes_in_eeprom != 0xFFFF)	{			
	                myitoa((UINT8 *)myascii,sizeof(myascii)-1,number_of_bytes_in_eeprom);
				    /* send out the serial port */
    			    myascii[4] = '\0';
                    drvUSARTWriteString((UINT8 *)myascii,sizeof(myascii));                   
                } else {
				    drvUSARTPutChar('0');
                } 
				drvUSARTWriteString((UINT8 *)CR_LF_STRING,sizeof(CR_LF_STRING));
	} else if (record_to_eeprom) {
	        /* Handle CR and BS chars separately. If unsuccessful in storing to eeprom
			   then output error message, otherwise store (except for BS) and echo */
	        if (data_received == CR_CHAR) {
			    if(drvWriteEeprom(next_eeprom_address, data_received)) {
			    	drvUpdateEepromDataCount(1);
	                drvUSARTPutChar(data_received);
					/* Tack on the LF char */
					if(drvWriteEeprom(next_eeprom_address, LF_CHAR)) {
			            drvUpdateEepromDataCount(1);
		                drvUSARTPutChar(LF_CHAR);
                    } else 
				        drvUSARTWriteString((UINT8 *)EEPROM_FULL_STRING,sizeof(EEPROM_FULL_STRING));
                } else 
				    drvUSARTWriteString((UINT8 *)EEPROM_FULL_STRING,sizeof(EEPROM_FULL_STRING));
            } else if (data_received == BACKSPACE_CHAR) {
			    /* Just adjust the count. */
			    drvUpdateEepromDataCount(-1);
	        } else {
			    if(drvWriteEeprom(next_eeprom_address, data_received)) {
			        drvUpdateEepromDataCount(1);
	                drvUSARTPutChar(data_received);
                } else 
				    drvUSARTWriteString((UINT8 *)EEPROM_FULL_STRING,sizeof(EEPROM_FULL_STRING));
            }

    } else 
	        drvUSARTPutChar(data_received);



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

    number_of_bytes_used_in_eeprom = drvRead16Eeprom(EEPROM_DATA_COUNT_ADDR);

	if ( number_of_bytes_used_in_eeprom == 0xFFFF ) {
        number_of_bytes_used_in_eeprom = 0;
		next_eeprom_address = EEPROM_DATA_START_ADDR;
    } else 
	    next_eeprom_address = number_of_bytes_used_in_eeprom;


}


/* do we have to manage a buffer here in case the eeprom is not ready? */
UINT8 drvWriteEeprom(UINT16 addr, UINT8 data)
{
    if (addr == EEPROM_CAPACITY) 
	    return(FALSE);

    /* Wait for completion of previous write */
    /*while(EECR & (1<<EEPE))*/
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & (EEPROM_PRG_EN))
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

	return(TRUE);
    
}

UINT8 drvReadEeprom(UINT16 addr) {

    /* Wait for completion of previous write */
    while(drvReadReg(EEPROM_BASE,EEPROM_CTRL_OFFSET) & (EEPROM_PRG_EN))
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

UINT16 drvRead16Eeprom(UINT16 addr) {

    volatile UINT16 data;
    data = drvReadEeprom(addr)<<8;
    data |= drvReadEeprom(addr+1);

	return data;
}
void drvUpdateEepromDataCount(INT16 increment) {

	number_of_bytes_used_in_eeprom+=increment;
	if (number_of_bytes_used_in_eeprom < 0 )
	    number_of_bytes_used_in_eeprom = 0;
    else if (number_of_bytes_used_in_eeprom >= EEPROM_CAPACITY-EEPROM_DATA_START_ADDR)
	    number_of_bytes_used_in_eeprom = EEPROM_CAPACITY-EEPROM_DATA_START_ADDR;
    else 
	    next_eeprom_address = EEPROM_DATA_START_ADDR+number_of_bytes_used_in_eeprom;
    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR, (number_of_bytes_used_in_eeprom>>8));
    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR+1, (number_of_bytes_used_in_eeprom&0xFF));
}

void drvResetEepromDataCount() {

    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR, 0);
    drvWriteEeprom(EEPROM_DATA_COUNT_ADDR+1, 0);

	number_of_bytes_used_in_eeprom = 0;
	next_eeprom_address = EEPROM_DATA_START_ADDR;
}


void init_gpio(UINT16 port) {
 drvWriteReg(DRV_PORTB,DRV_GPIO_PORT_OFFSET , 0xFF);
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



