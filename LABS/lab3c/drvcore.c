#include "..\inc\atmega2560.h"

void myitoa(UINT8 myascii[],UINT16 value) {
 
	volatile UINT8 i;
	volatile UINT16 divisor;

	divisor = value;

    for(i=sizeof(myascii)-1;i>0;i--) {
	    myascii[i] = (divisor/(10*i))+0x30;
	    divisor = divisor%(10*i);
    }
    myascii[0] = divisor+0x30;
}
