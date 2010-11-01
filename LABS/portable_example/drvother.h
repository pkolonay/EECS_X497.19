/* Copyright 2003 Aaron Baranoff                             */
/* Your non-API function proto types and internal structures */


#ifndef DRVOTHER_H

#define DRVOTHER_H

#include "drvport.h"


typedef struct 
{
	/* TRUE | FALSE */
	UINT8 txenable;				/* enable the transmiter */
	/* DRV_TXBITSPERCLK_1 | DRV_TXBITSPERCLK_2 | DRV_TXBITSPERCLK_3 | DRV_TXBITSPERCLK_4 */
	UINT8 txbitsperclk;			/* number of tx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	UINT8 txdatainv;			/* TX data invert - invert each bit on TX */
	/* DRV_ODD | DRV_EVEN */
	UINT8 txparity;				/* TX Parity 0 Even 1 Odd */
	/* DRV_PARITY_ENABLED | DRV_PARITY_NOT_EN */
	UINT8 txparity_noten; 		/* TX Parity not enabled - 0 Enabled 1 not enabled */
	/* TRUE | FALSE */
	UINT8 txerr;				/* TX Error Status - Last read value */ 
	/* TRUE | FALSE */
	UINT8 txrdy;				/* TX ready for data */
} DRVTXCTRL, * PDRVTXCTRL;

typedef struct 
{
	/* TRUE | FALSE */
	UINT8 rxenable;					/* enable the reciever */
	/* DRV_RXBITSPERCLK_1 | DRV_RXBITSPERCLK_3 | DRV_RXBITSPERCLK_3 | DRV_RXBITSPERCLK_4 */
	UINT8 rxbitsperclk;				/* number of rx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	UINT8 rxdatainv;				/* RX data invert - invert each bit on TX */
	/* DRV_RXODD | DRV_RXEVEN */
	UINT8 rxparity;					/* RX Parity 0 Even 1 Odd */
	/* DRV_RXPARITY_ENABLED | DRV_RXPARITY_NOT_EN */
	UINT8 rxparity_noten;			/* RX Parity not enabled - 0 Enabled 1 not enabled */
	/* TRUE | FALSE */
	UINT8 rxerr;					/* RX Error Status - LAst value read */ 
	/* TRUE | FALSE */
	UINT8 rxrdy;					/* RX has data */
} DRVRXCTRL, * PDRVRXCTRL;

typedef struct 
{
	UINT32 		baseaddr; /* base address of the device */
	UINT32		errors;
	DRVTXCTRL 	txctrl;	  /* tx control */
	DRVRXCTRL 	rxctrl;	  /* rx control */
	
} DRVCTRL, * PDRVCTRL;

/* init TX */
extern void drvInitTx(PDRVCTRL ctrl);
/* init RX */
extern void drvInitRx(PDRVCTRL ctrl);


#endif