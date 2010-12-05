/*****************************************************************************/
/* Filename: main.c                                                          */
/* Description: Driver program to run code written for Lab 5 of EECS_X497.19.*/
/* Date: 12-05-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/
#include "drvapi.h"


/* Initialize the hardare, display useage message and start processing data. */
int main() {


    init_system();

	printStr(">> Paul Kolonay EECS_X497.19 Lab 5 <<\n\r");

    printUseage();

	start_processing();
    
    while (1) {
	;
    }


}
