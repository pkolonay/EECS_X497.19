/*****************************************************************************/
/*                                                                           */
/* Filename: lab3.c                                                          */
/* Description: Implementation of a delay routine using the atmega2560       */
/*              Timer1 on the STK600 platform. This particular version uses  */
/*              a busy wait loop to poll the timer1 value. The delay is used */
/*              in the main routine between LED on/off toggles. Button       */
/*              presses are also read through PORTD and LEDs are             */
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

/* This will result in a 100 mSec delay for a system with F_CPU=1MHz and */
/* timer prescaler set to 8.                                             */
#define DELAY 12500

/* Other delay values can be set uing the following:                     */
/* DELAY = F_CPU/PRESCALE * delay_in_seconds                             */
/*       = 100000/8 * 1  (scaled up from 100 mSec)                       */
/*       = 12500                                                         */



/* Delay using polling of timer register.   */
/* this delay routine uses the 16bit Timer1 */
void delay() {

    /* holds the 16 bit value from the timer */
	volatile UINT16 timer_value = 0;

	/* prescale set to divide by 8 */
	HWREG(TCCR1B) |= TC1_CK_8;

	/* reset the counter */
	HWREG(TCNT1H) = 0;
    HWREG(TCNT1L) = 0;

    /* read the timer value and exit when match is reached */
	while( 1 ) {
	    timer_value = HWREG(TCNT1L);
		timer_value |= (HWREG(TCNT1H) << 8);
		if (timer_value >= (UINT16) DELAY) return;
    }
}

int main()
{
    /* used to iterate through the LEDs/PINDs */
    UINT16 i;


	/* set PORTB for output */
    HWREG(DDRB) = 0xff; 
	/* set PORTD for input */
	HWREG(DDRD) = 0x00; 
	    
    /* turn the LEDs off */
    HWREG(PORTB) = 0xff;

	while(1) {
	                  
		/* cycle through all the LEDs */  
        for( i = 0;i<8;i++) {

            /* toggle LED on */				
            HWREG(PORTB) ^= (1<<i);
    		delay();
        
		    /* toggle LED off */
	        HWREG(PORTB) ^= (1<<i);
    		delay();

			/* check for button press on pin i and exit if detected */
		    if ((UINT8)~HWREG(PIND) & (1<<i)) break;

		}
    }
}
