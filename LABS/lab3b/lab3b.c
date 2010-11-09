/*****************************************************************************/
/*                                                                           */
/* Filename: lab3b.c                                                         */
/* Description: Implementation of a delay routine using the atmega2560       */
/*              Timer0 on the STK600 platform. This particular version uses  */
/*              an interrupt based approach to determine when the timer has  */
/*              reached the delay time. This is a re-implementation of the   */
/*              lab3 program and as such the main code is the same.The delay */
/*              is used in the main routine between LED on/off toggles.      */
/*              Button presses are also read through PORTD and LEDs are      */
/*              only toggled up to the current button being pressed. All     */
/*              LEDs are toggled if no button is being pressed.              */  
/*                                                                           */
/*              This file was created as part of the Fall 2010 EECS_X497.19  */
/*              class Lab3.                                                  */ 
/*                                                                           */
/* Date:   11-7-2010                                                         */
/* Author: Paul Kolonay                                                      */
/*****************************************************************************/
#include "..\inc\atmega2560.h"
#include "..\inc\hw_timer.h"

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
const UINT8 DELAY = 100;

/* flag used by ISR to indicate timout to main function */
volatile UINT8 timeout;

void timer_init(UINT8 delay) { 

    /* global interrupt disable */
    cli();

    /* reset timeout flag */
    timeout = 0;

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

/* This function simply sets up the timer and loops until */
/* the timers rolls over.                                 */
void delay(int ms) {

    /* set up timer */
	timer_init(ms);

    /* wait for interrupt flag */
	while (!timeout) {
	;
	}

    return;
}

void timer_interrupt() {

	/* set some flag variable */
    timeout = 1;

}

/* in you port.c code */
/* timer 0 overflow interrupt service routine */
void __vector_23 (void) 
{ 
	/* set some flag variable */
    timer_interrupt();
}



int main()
{
    /* used as loop variable for incrementing through PINDs/LEDs */
	UINT8  j;



	/* set PORTB for output */
    HWREG(DDRB) = 0xff; 
	/* set PORTD for input */
	HWREG(DDRD) = 0x00; 
	    

    /* turn off the LEDs */
    HWREG(PORTB) = 0xff;

	while(1) {
	                  
		/* cycle through all the LEDs */  
        for( j = 0;j<8;j++) {

            /* toggle LED  */				
            HWREG(PORTB) ^= (1<<j);
			delay(DELAY);
        
		    /* toggle LED  */
	        HWREG(PORTB) ^= (1<<j);
		    delay(DELAY);

			/* check for button press */
		    if ((UINT8)~HWREG(PIND) & (1<<j)) break;

		}
    }
}
