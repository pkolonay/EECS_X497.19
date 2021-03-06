#include "..\inc\atmega2560.h"
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


void drvWriteUint16Reg(const UINT16 base, UINT16 offset, UINT16 value) {
    /* write hi then low */
    drvWriteReg(base,offset+1,value>>8);
    drvWriteReg(base,offset,(UINT8)(value&0xFF));
}


void process() {
    static   UINT8 record_to_eeprom;
	volatile UINT8 i;
	/* for a 4 digit ascii string to output the number of bytes in the eeprom */
	volatile UINT8 myascii[5]; 
	volatile UINT16 number_of_bytes_in_eeprom;
    volatile RingBuff_Data_t data_received;
	volatile bool isEmpty;
	volatile UINT16 j;
    
	/* Initialize the ring buffer for serial comm */
	RingBuffer_InitBuffer((RingBuff_t *)&rbuff);

    while(1) {
	    isEmpty = RingBuffer_IsEmpty((RingBuff_t *)&rbuff);
	    if(isEmpty == false) {
		    data_received = RingBuffer_Remove((RingBuff_t *)&rbuff);
            if (data_received == RECORDING_CONTROL_CHAR) {
	            /* if currently recording then stop else start recording */
	            if(!record_to_eeprom) {
			        /* reset character count */
			        drvResetEepromDataCount();
	                record_to_eeprom = TRUE;
                } else {
		            record_to_eeprom = FALSE;
                }
            } else if (data_received == PLAYBACK_CHAR)  {
			    for(i = 1;i < next_eeprom_address;i++)
	                drvUSARTPutChar(drvReadEeprom(i));
            } else if (data_received == DUMP_NUMBER_OF_BYTES_CHAR) {
	            /* initialize array */
	            drvUSARTWriteString((UINT8 *)BYTES_STORED_STRING,sizeof(BYTES_STORED_STRING));
				/* initialize string */
				myascii[0]='\0';
				/* read the write count from eeprom and convert to ascii */
				number_of_bytes_in_eeprom = drvReadEeprom(EEPROM_DATA_COUNT_ADDR)<<8;
				number_of_bytes_in_eeprom |= drvReadEeprom(EEPROM_DATA_COUNT_ADDR+1);
				if (number_of_bytes_in_eeprom >= 0)	{			
	                myitoa((UINT8 *)myascii,sizeof(myascii)-1,number_of_bytes_in_eeprom);
				    /* send out the serial port */
					myascii[4] = '\0';
                    drvUSARTWriteString((UINT8 *)myascii,sizeof(myascii));                   
                } else {
				    drvUSARTPutChar('0');
                } 
		    	drvUSARTWriteString((UINT8 *)CR_LF_STRING,sizeof(CR_LF_STRING));
	        } else if (record_to_eeprom) {
                drvWriteEeprom(next_eeprom_address, data_received);
			    drvUpdateEepromDataCount();
	            drvUSARTPutChar(data_received);
	            if (data_received == CR_CHAR) {
				    drvWriteEeprom(next_eeprom_address, LF_CHAR);
			        drvUpdateEepromDataCount();
		            drvUSARTPutChar(LF_CHAR);
                } else if (data_received == BACKSPACE_CHAR) {
			        drvUpdateEepromDataCount(-1);
                    drvWriteEeprom(next_eeprom_address, data_received);
	            }
            } else 
	            drvUSARTPutChar(data_received);
	    }
    }

}
