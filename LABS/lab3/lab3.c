#include "..\inc\atmega2560.h"

#define UINT16 unsigned int
#define UINT8 unsigned char

/* delay in milliseconds */
static const UINT16 DELAY = 1000;

/* set to the frequency of the cpu (khz)*/
static const UINT16 CPU_FREQ = 1000;

void delay(int milliSeconds) {

    /* holds the 16 bit value from the timer */
	volatile UINT16 timer_value = 0;

	/* 1/10th of a second for 1MHz clock CPU clock */
	volatile UINT16 compare = 12500;

	/* no prescale */
	HWREG(TCCR1B) |= CS01;

	/* reset the counter */
	HWREG(TCNT1H) = 0;
    HWREG(TCNT1L) = 0;

    /* read the timer value and exit when match is reached */
	while( 1  ) {
	    timer_value = HWREG(TCNT1L);
		timer_value |= (HWREG(TCNT1H) << 8);
		if (timer_value >= compare) return;
    }
}

int main()
{
    UINT16 i;




	/* set POTRB for output */
    HWREG(DDRB) = 0xff; 
	/* set PORTD for input */
	HWREG(DDRD) = 0x00; 
	    

    HWREG(PORTB) = 0xff;

	while(1) {
	                  
		/* cycle through all the LEDs */  
        for( i = 0;i<8;i++) {

            /* turn LED on */				
            HWREG(PORTB) ^= (1<<i);
    		delay(60);
        
		    /* turn LED off */
	        HWREG(PORTB) ^= (1<<i);
    		delay(60);


			/* check for button press */
		    if ((UINT8)~HWREG(PIND) & (1<<i)) break;

		}
    }
}
