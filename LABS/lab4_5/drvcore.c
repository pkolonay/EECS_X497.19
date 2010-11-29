/*****************************************************************************/
/* Filename: drvcore.c                                                       */
/* Description: Some utility functions used for Lab4/5 of EECS_X497.19.      */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
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
