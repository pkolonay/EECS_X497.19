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
