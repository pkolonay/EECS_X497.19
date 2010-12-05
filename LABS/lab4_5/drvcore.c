/*****************************************************************************/
/* Filename: drvcore.c                                                       */
/* Description: Some utility functions used for Lab 5 of EECS_X497.19.       */
/* Date: 12-05-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
#include "drvcore.h"


/**
  * Function: myitoa
  * Description: Convert 16-bit interger value to ascii string.
  * Parameters: myascii - array of ascii values.
  *             length -  length of ascii string.
  *             value - integer number to be converted
  */
void myitoa(UINT8 myascii[],UINT16 length, UINT16 value) {
 
	volatile UINT8 i,j;
	volatile UINT16 divisor,dividend;

	divisor = value;

    /* work from highest power down to uints */
	/* but place characters in array in the opposite order */
    for(i=0;i<length-1;i++) {
    	dividend = 1;
	    for(j=1;j<=(length-i-1);j++) dividend *= 10;
	    myascii[i] = (divisor/dividend)+MAP_DIGIT_TO_ASCII;
	    divisor = divisor%dividend;
    }
    myascii[length-1] = divisor+MAP_DIGIT_TO_ASCII;
}


/**
  * Used to test a bit in a in a given byte at a given address.
  */
UINT8 drvTestBit(UINT16 addr, UINT16 offset, UINT8 position) {
    volatile UINT8 value;

    value = (UINT8)~drvReadReg(addr,offset) & (1<<position);

    return( value >> position);
}


/**
  * Read two consecutive 8 bit locations and concatenate into a UINT16.
  * The hi byte is read first and then the low as spec'd in the atmega
  * datasheet. This probably should be an atomic operation.
  */
void drvWriteUint16Reg(const UINT16 base, UINT16 offset, UINT16 value) {
    /* write hi then low */
    drvWriteReg(base,offset+1,value>>8);
    drvWriteReg(base,offset,(UINT8)(value&0xFF));
}

/**
 * Check for byte in ring buffer and process as needed.
 */
void process() {
    static   UINT8 record_to_eeprom;
	volatile UINT8 i;
	/* for a 4 digit ascii string to output the number of bytes in the eeprom */
	volatile UINT8 myascii[5]; 
	volatile UINT16 number_of_bytes_in_eeprom;
    volatile RingBuff_Data_t data_received;

	/* Initialize the ring buffer for serial comm */
	RingBuffer_InitBuffer((RingBuff_t *)&rbuff);
    while(1) {
	    /* Anything in the buffer? */
	    if(!RingBuffer_IsEmpty((RingBuff_t *)&rbuff)) {
		    /* Get it and process it */
		    data_received = RingBuffer_Remove((RingBuff_t *)&rbuff);
			switch(data_received) {
    		    case RECORDING_CONTROL_CHAR:
	            /* if currently recording then stop else, start recording! */
	                if(!record_to_eeprom) {
			            /* reset character count and pointers*/
			            drvResetEepromDataCount();
	                    record_to_eeprom = TRUE;
                        drvUSARTWriteString((UINT8 *)RECORD_ON_STR);
                    } else {
		                record_to_eeprom = FALSE;
                        drvUSARTWriteString((UINT8 *)RECORD_OFF_STR);
                    }
				    break;
                case PLAYBACK_CHAR:
				    drvUSARTWriteString((UINT8 *)DUMPING_EEPROM_STR);
			        for(i = EEPROM_DATA_START_ADDR;i < next_eeprom_address;i++)
	                    drvUSARTPutChar(drvReadEeprom(i));
				    drvUSARTWriteString((UINT8 *)CR_LF_STRING);
                    break;
                case DUMP_NUMBER_OF_BYTES_CHAR:
	                /* initialize array */
	                drvUSARTWriteString((UINT8 *)BYTES_STORED_STRING);
				    /* initialize string */
				    myascii[0]='\0';
				    /* read the write count from eeprom and convert to ascii */
				    number_of_bytes_in_eeprom = drvRead16Eeprom(EEPROM_DATA_COUNT_ADDR);
				    if (number_of_bytes_in_eeprom != 0xFFFF)	{			
	                    myitoa((UINT8 *)myascii,sizeof(myascii)-1,number_of_bytes_in_eeprom);
				        /* send out the serial port */
    			        myascii[4] = '\0';
                        drvUSARTWriteString((UINT8 *)myascii);                   
                    } else {
				        drvUSARTPutChar('0');
                    } 
				    drvUSARTWriteString((UINT8 *)CR_LF_STRING);
				    break;
                case BACKSPACE_CHAR:
                   /* Just adjust the count. */
                    if (record_to_eeprom) drvUpdateEepromDataCount(-1);
				    break;
                default:
                    if (record_to_eeprom) {
                        /* If unsuccessful in storing to eeprom then output error message, 
						   otherwise store and echo */
   		                if(drvWriteEeprom(next_eeprom_address, data_received)) {
    	                    drvUpdateEepromDataCount(1);
                            drvUSARTPutChar(data_received);
                        } else {
			                drvUSARTWriteString((UINT8 *)EEPROM_FULL_STRING);
							record_to_eeprom = FALSE;
                            drvUSARTWriteString((UINT8 *)RECORD_OFF_STR);
							break;
                        }
                        if (data_received == CR_CHAR) {
				            /* Tack on the LF char */
				            if(drvWriteEeprom(next_eeprom_address, LF_CHAR)) {
		                        drvUpdateEepromDataCount(1);
	                            drvUSARTPutChar(LF_CHAR);
                            } else {
    		                    drvUSARTWriteString((UINT8 *)EEPROM_FULL_STRING);
						        record_to_eeprom = FALSE;
                                drvUSARTWriteString((UINT8 *)RECORD_OFF_STR);
						        break;
                            }
                        }

                    } else  /* not recording: just echo character to serial port */
	                    drvUSARTPutChar(data_received);
            }
        }
    }
}

void printUseage() {

	drvUSARTWriteString((UINT8 *)"Useage:\n\r");
	drvUSARTWriteString((UINT8 *)"Control-z toggle record on/off\n\r");
	drvUSARTWriteString((UINT8 *)"Control-y playback recorded characters\n\r");
	drvUSARTWriteString((UINT8 *)"Control-n display the number of characters recorded.\n\r");

}
