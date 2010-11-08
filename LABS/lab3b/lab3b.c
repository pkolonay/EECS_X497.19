#include "..\inc\atmega2560.h"
#include "..\inc\hw_timr.h"

#define UINT16 unsigned int
#define UINT8 unsigned char

/* Timer Eqns: 
 *   Resolution
 *	     1/F_CPU = 1/cycles/sec = seconds/cycle
 *          1MHz clk = 1uSec resolution
 *	     Pre-scaled 
 *		   res = F_CPU/PRESCALE
 *		   1mSec resolution with prescale of 1024 and CPU_FREQ of 1MHz
 *		 SW resolution
 *		   res = TCNTinit/F_CPU
 *         max resolution of 255uSec for counter 0.
 *
 *       Prescale+SW
 *		   res = TCNTinit*PRESCALE/CPU_FREQ
 *		   for TCNT0 : CPU_FREQ 1MHz : PRESCALE 1024 
 *		     maxres = 255 * 1024/1000000 = 0.26112s
 */

/* delay in milliseconds */
static const UINT8 DELAY = 100;

/* set to the frequency of the cpu (khz)*/
static const UINT16 CPU_FREQ = 1000;

/* used by ISR to indicate timout*/
volatile UINT8 timeout = 0;
volatile UINT8 WD_timeout = 0;


volatile UINT8 bad_interrupt = 0;

void timer_init(UINT8 delay) { 

    cli();

    /* reset timeout flag */
    timeout = 0;

   /* set pre-scaler to F_CPU/1024 */
   HWREG(TCCR0B) |= (UINT8)(CS02|CS00);
    
/* Program the timer with the value you want 
   which is (256-the number of counts) into TCNT0. */ 
   HWREG(TCNT0) = 256-delay; 

   /* Enable Overflow Interrupt for Counter 0 */
   HWREG(TIMSK0) = TOIE0; 

   /* Enable Global Interrupts */ 
   sei();

   }

void delay(int ms) {

    /* set up timer */
	timer_init(50);

    /* wait for interrupt flag */
	while (!timeout) {
	;
	}

    return;
}

void timer_interrupt() {

	static volatile UINT16 timer_interrupt_counter;
 

    timer_interrupt_counter++;

    if ( timer_interrupt_counter > 10 ) {
	/* set some flag variable */
        timeout = 1;
		timer_interrupt_counter = 0;
    }



}

/* in you port.c code */
/* timer 0 overflow */
void __vector_23 (void) 
{ 
	/* set some flag variable */
    timer_interrupt();
}



int main()
{
	UINT8  j;

    bad_interrupt = 0;
	HWREG(TCCR0A) = 0x0;

	/* set PORTB for output */
    HWREG(DDRB) = 0xff; 
	/* set PORTD for input */
	HWREG(DDRD) = 0x00; 
	    


    HWREG(PORTB) = 0xff;

	while(1) {
	                  
		/* cycle through all the LEDs */  
        for( j = 0;j<8;j++) {

            /* toggle LED  */				
            HWREG(PORTB) ^= (1<<j);
			delay(200);
        
		    /* toggle LED  */
	        HWREG(PORTB) ^= (1<<j);
		    delay(60);

			/* check for button press */
		    if ((UINT8)~HWREG(PIND) & (1<<j)) break;

		}
    }
}
