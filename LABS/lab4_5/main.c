/*****************************************************************************/
/* Filename: main.c                                                          */
/* Description: Driver program to run code written for Lab4/5 of             */
/*              EECS_X497.19.                                                */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
#include "drvapi.h"



int main() {


	init_gpio(DRV_PORTB);
	init_gpio(DRV_PORTD);

    init_timer();

    init_usart0();

    init_eeprom();
    
    while (1) {
	;
    }


}
