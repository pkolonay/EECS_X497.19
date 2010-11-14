
#ifndef __drvcore_H__
#define __drvcore_H__

#include "..\inc\atmega2560.h"


typedef struct 
{
    UINT8    dir1; 
    UINT8    dir2; 
    UINT8    dir3; 
    UINT8    dir4; 
    UINT8    dir5; 
    UINT8    dir6; 
    UINT8    dir7; 
    UINT8    dir8; 
   	

} DRVGPIODIR, * PDRVGPIODIR;

typedef struct 
{
    UINT8    port1; 
    UINT8    port2; 
    UINT8    port3; 
    UINT8    port4; 
    UINT8    port5; 
    UINT8    port6; 
    UINT8    port7; 
    UINT8    port8; 
   	

} DRVGPIOPORT, * PDRVGPIOPORT;

typedef struct 
{
    UINT8    pin1; 
    UINT8    pin2; 
    UINT8    pin3; 
    UINT8    pin4; 
    UINT8    pin5; 
    UINT8    pin6; 
    UINT8    pin7; 
    UINT8    pin8; 
   	

} DRVGPIOPIN, * PDRVGPIOPIN;

typedef struct 
{
    UINT8 		baseaddr; /* base address of the device */
    UINT8		errors;
    DRVGPIODIR 	dir;	  /* port direction */
    DRVGPIOPORT pin;	  /* port output    */
    DRVGPIOPIN  data;     /* port input     */
} DRVCTRL, * PDRVCTRL;


#define ADDR_MULTIPLIER 1

UINT8 read_pin(UINT8 port, UINT8 pin);
void delay_mSec();

#endif /* drvcore */
