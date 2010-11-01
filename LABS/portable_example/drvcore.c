/* Copyright 2003 Aaron Baranoff                                      */
/* Your behind the scenes functions                                   */
/* THIS FILE HAS NO PORTABLITY dependencies and should not have to    */
/* change for a different enviroment.                                 */

#include "drvapi.h"
#include "drvreg.h"


/* init TX */
void drvInitTx(PDRVCTRL ctrl)
{
	PDRVTXCTRL txctrl=&(ctrl->txctrl);
	UINT8 val = 0;

	/* TRUE | FALSE */
	if (txctrl->txenable)
	{
		val |= DRV_TXENABLE;	 /* enable the reciever */
	}
	/* DRV_TXBITSPERCLK_1 | DRV_TXBITSPERCLK_3 | DRV_TXBITSPERCLK_3 | DRV_TXBITSPERCLK_4 */
	if (txctrl->txbitsperclk > DRV_TXBITSPERCLK_4) 
	{
		txctrl->txbitsperclk = DRV_TXBITSPERCLK_4;
	}							/* number of tx bits per sys clock (1-4) */
	val |= txctrl->txbitsperclk * DRV_TXBITSPERCLK;	 /* number of tx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	if (txctrl->txdatainv)
	{
		val |= DRV_TXDATAINV;	/* TX data invert - invert each bit on TX */
	}
	/* DRV_RXODD | DRV_RXEVEN */
	if (txctrl->txparity)
	{
				val |= DRV_TXPARITY; /* TX Parity 0 Even 1 Odd */
	}
	/* DRV_TXPARITY_ENABLED | DRV_TXPARITY_NOT_EN */
	if(txctrl->txparity_noten)
	{
				val |= DRV_TXPARITY_NOTEN; /* TX Parity not enabled - 0 Enabled 1 not enabled */
	}
	
	
 	drvWriteReg(ctrl, DRV_TXREG, val);	/* program TX config into device */  	
} 

/* init RX */
void drvInitRx(PDRVCTRL ctrl)
{
	PDRVRXCTRL rxctrl=&(ctrl->rxctrl);
	UINT8 val = 0;

	/* TRUE | FALSE */
	if (rxctrl->rxenable)
	{
		val |= DRV_RXENABLE;	 /* enable the tranmitter */
	}
	/* DRV_RXBITSPERCLK_1 | DRV_RXBITSPERCLK_3 | DRV_RXBITSPERCLK_3 | DRV_RXBITSPERCLK_4 */
	if (rxctrl->rxbitsperclk > DRV_RXBITSPERCLK_4) 
	{
		rxctrl->rxbitsperclk = DRV_RXBITSPERCLK_4;
	}							
	val |= rxctrl->rxbitsperclk * DRV_RXBITSPERCLK;	 /* number of rx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	if (rxctrl->rxdatainv)
	{
		val |= DRV_RXDATAINV;	/* RX data invert - invert each bit on RX */
	}
	/* DRV_TXODD | DRV_TXEVEN */
	if (rxctrl->rxparity)
	{
				val |= DRV_RXPARITY; /* RX Parity 0 Even 1 Odd */
	}
	/* DRV_RXPARITY_ENABLED | DRV_RXPARITY_NOT_EN */
	if(rxctrl->rxparity_noten)
	{
				val |= DRV_RXPARITY_NOTEN; /* RX Parity not enabled - 0 Enabled 1 not enabled */
	}

 	drvWriteReg(ctrl, DRV_RXREG, val);	/* program RX config into device */  	

}