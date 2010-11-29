/*****************************************************************************/
/* Filename: drvapi.h                                                        */
/* Description: Driver program to run code written for Lab4/5 of             */
/*              EECS_X497.19.                                                */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/

#ifndef __drvapi_H__
#define __drvapi_H__


#include "drvcore.h"

#define SDK600

#ifdef SDK600
#define NUMBEROFLEDS 8

#define LED_OFF 1
#define LED_ON  0
#define LEDS    DRV_PORTB

#endif

void board_led_on(UINT8);

void board_led_off(UINT8);


void drvinit();


void delay_mSec();

void init_timer();

void init_usart0();

void init_gpio(UINT8);

void init_eeprom();

#endif
