/* Copyright 2003 Aaron Baranoff                                      */
/* Your API functions the functions your customer is expected to call */
/* THIS FILE HAS NO PORTABLITY dependencies and should not have to    */
/* change for a different enviroment.                                 */

#include "drvapi.h"
#include "drvreg.h"

/* Init the hardware via control struct */
void drvInitDevice(PDRVCTRL ctrl)
{
	ctrl->errors = 0;
	drvInitTx(ctrl);
	drvInitRx(ctrl);
}

/* main loop actually called via a function in drvport.c */
void drvMainTask(PDRVCTRL ctrl)
{
	UINT8 last_read;

	while (1)
	{
		/* do something */
		last_read = drvReadRx(ctrl);
		drvWriteTx(ctrl, last_read);
		drvSleep(1);
	}
}


/* read the last char recieved if it was there was one otherwise wait */
UINT8 drvReadRx(PDRVCTRL ctrl)
{
	UINT8 status_val, rx_val;

 	status_val = drvReadReg(ctrl, DRV_RXREG);

	do 
	{
		drvSleep(1);
		ctrl->rxctrl.rxerr = status_val & (UINT8)DRV_RXERR;
		if (ctrl->rxctrl.rxerr)	 /* rx error */
		{	
			ctrl->errors++;
		}
		ctrl->rxctrl.rxrdy = status_val & (UINT8)DRV_RXRDY;
	} while (!ctrl->rxctrl.rxrdy); /* loop until there is data */
 		
 	rx_val = drvReadReg(ctrl, DRV_TXDATA);	 /* read rx data */

	return rx_val;
}


/* write TX char if it is read otherwise wait */
void drvWriteTx(PDRVCTRL ctrl, UINT8 tx_val)
{
	UINT8 status_val;

 	status_val = drvReadReg(ctrl, DRV_TXREG);

	do 
	{
		drvSleep(1);
		ctrl->rxctrl.rxerr = status_val & (UINT8)DRV_TXERR;
		if (ctrl->txctrl.txerr)	  /* tx error */
		{	
			ctrl->errors++;
		}
		ctrl->rxctrl.rxrdy = status_val & (UINT8)DRV_TXRDY;
	} while (!ctrl->txctrl.txrdy); /* loop until there is room to tx the data */
 		
 	drvWriteReg(ctrl, DRV_TXDATA, tx_val);	 /* read rx data */
}


