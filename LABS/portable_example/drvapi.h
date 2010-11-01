/* Copyright 2003 Aaron Baranoff               */
/* Your API function proto types               */

#ifndef DRVAPI_H

#define DRVAPI_H

#include "drvport.h"

/* Init the hardware via control struct */
void drvInitDevice(PDRVCTRL ctrl);
/* main loop actually called via a function in drvport.c */
void drvMainTask(PDRVCTRL ctrl);
/* read the last char recieved if it was there was one otherwise wait */
UINT8 drvReadRx(PDRVCTRL ctrl);
/* write TX char if it is read otherwise wait */
void drvWriteTx(PDRVCTRL ctrl, UINT8 tx_val);

/* the folling are defined in drvport.h */

/* wrapper for writing register */
void drvWriteReg(PDRVCTRL ctrl, UINT32 addr, UINT8 val);
/* wrapper for writing register */
UINT8 drvReadReg(PDRVCTRL ctrl, UINT32 addr);

/* sleep for x number of millisec */
void drvSleep(UINT32 millisec);
/* Driver Initilization */
INT8 drvInit(void);


#endif
