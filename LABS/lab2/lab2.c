/* LAB 2 - Writing Portable Device Drivers */
/* slightly more portable version of LAB1  */
/*                                         */
/* Paul Kolonay                            */

#include "atmega2560.h"

void delay(volatile unsigned int val)
{
	volatile unsigned int temp;
	volatile unsigned int temp2;

	for(temp = 0; temp < val; temp++) 
		for (temp2 = 0; temp2 < val; temp2 ++) ;
}

int main(void)
{
    HWREG(DDRB) = 0xff;                                                             \
	while(1) {
	 	HWREG(PORTB) = 0x03;
	 	delay(100);
	 	HWREG(PORTB) = 0x0c;
	 	delay(100);
	 	HWREG(PORTB) = 0x30;
	 	delay(100);
	 	HWREG(PORTB) = 0xc0;
	 	delay(100);
	}

	return(0);
}

