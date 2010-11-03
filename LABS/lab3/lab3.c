#include "..\inc\atmega2560.h"

#define UINT16 unsigned int
#define UINT8 unsigned char

/* delay in milliseconds */
static const UINT16 DELAY = 1000;

/* set to the frequency of the cpu (khz)*/
static const UINT16 CPU_FREQ = 1000;


ISR(TIMER1_OVF_vect)
{
  static UINT8 scaler;

}

void delay_int() {
;
/* reset counter */
/* load compare register */
/* enable timer interrupt */
/* wait for interrupt flag */
}

void delay(int milliSeconds) {

    /* holds the 16 bit value from the timer */
	volatile UINT16 timer_value = 0;

	/* 1/20th of a second for 1MHz clock CPU clock */
	volatile UINT16 compare = 49999;

	/* no prescale */
	HWREG(TCCR1B) |= CS10;

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
	UINT8  j;

	/* loop limit */
	int delay_multiplier = 20;

	/* set POTRB for output */
    HWREG(DDRB) = 0xff; 
	/* set PORTD for input */
	HWREG(DDRD) = 0x00; 
	    

	while(1) {
	                  
		/* cycle through all the LEDs */  
        for( j = 0;j<8;j++) {

            /* turn LED on */				
            HWREG(PORTB) = (UINT8)~(1<<j);
	    	/* the delay provides 1/20th of a second delay */
		    /* calling it 10 times should result in .5 second delay */
    		for(i=0;i<delay_multiplier;i++) delay(60);
        
		    /* turn LED off */
	        HWREG(PORTB) |= (UINT8)(1<<j);
		    for(i=0;i<delay_multiplier;i++) delay(60);

			/* check for button press */
		    if ((UINT8)~HWREG(PIND) & (1<<j)) break;

		}
    }
}
