#include "..\inc\atmega2560.h"
#include "..\inc\hw_timer.h"
#include "drvcore.h"

	UINT8 hit_it = 0;

/* wrapper for writing register */
void drvWriteReg(PDRVCTRL ctrl, UINT16 addr, UINT8 val)
{
	*((volatile UINT8 *)(ctrl->baseaddr + (addr*ADDR_MULTIPLIER))) = val;
}

/* wrapper for writing register */
UINT8 drvReadReg(PDRVCTRL ctrl, UINT16 addr)
{
	return *((volatile UINT8 *)(ctrl->baseaddr + (addr*ADDR_MULTIPLIER)));
}

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

/* This function simply sets up the timer and loops until */
/* the timers rolls over.                                 */
void delay_mSec() {

    /* set up timer */
	timer_init(100);

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

void __vector_11(void)
{
	if(hit_it == 0) 
        hit_it =1;

}

DRVCTRL example;

/* set direction */
void init_port(UINT8 port_id) {

	example.baseaddr = port_id-2;


}

void write_pin(UINT16 port, UINT8 pin, UINT8 value) {

	/* set port for output */
	HWREG(port-1) |= 1<<pin; 

    if (value)
	/* output to port */
        HWREG(port) |= (1<<pin); 
    else
	    HWREG(port) &= (UINT8)~(1<<pin);
}


UINT8 read_pin(UINT16 port, UINT8 pin) {

	/* set port for input */
	HWREG(port-1) &= (UINT8)~pin; 

	return(HWREG(port-2) &= pin);

}
	    

