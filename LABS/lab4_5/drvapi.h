/*****************************************************************************/
/* Filename: drvapi.h                                                        */
/* Description: API declarations for Lab5 of EECS_X497.19.                   */
/* Date: 12-05-2010                                                          */
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

void printStr(UINT8 *);
void init_system();
void printUseage();
void start_processing();

#endif
