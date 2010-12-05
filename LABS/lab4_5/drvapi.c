/*****************************************************************************/
/* Filename: drvapi.c                                                        */
/* Description: API definition for Lab 5 of EECS_X497.19.                    */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
#include "drvapi.h"


/**
 * Initialize the system 
 * Parameters: None
 * Returns: Nothing
 */
void init_system() {

	init_gpio();

    timer_init(100);


    init_usart0();

    init_eeprom();

}


/** Print a string to the serial port. 
 * Parameter: string to send to serialport. *
 * Returns:   nothing                       */
void printStr(UINT8 *string) {

	drvUSARTWriteString(string);

}

void start_processing() {

    process();

}
