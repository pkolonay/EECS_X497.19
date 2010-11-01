/* Copyright 2003 Aaron Baranoff                                */
/* Your porting functions and default init,etc                  */
/* in this file is where the os/complier dependencies can occur */

#include "drvapi.h"
#include "drvreg.h"

/* wrapper for writing register */
void drvWriteReg(PDRVCTRL ctrl, UINT32 addr, UINT8 val)
{
	*((volatile UINT8 *)(ctrl->baseaddr + (addr*ADDR_MULTIPLIER))) = val;
}

/* wrapper for writing register */
UINT8 drvReadReg(PDRVCTRL ctrl, UINT32 addr)
{
	return *((volatile UINT8 *)(ctrl->baseaddr + (addr*ADDR_MULTIPLIER)));
}

/* sleep for x number of millisec (rounded up by a tick) */
void drvSleep(UINT32 millisec)
{
	task_delay((millisec/TICKS_PER_MS) + 1);
}


DRVCTRL	example;

/* an example for my unknown OS */
static void task(UINT8 special_os_stuff)
{
	drvMainTask(&example);
}

/* Driver Initilization */
INT8 drvInit(void)
{
	example.baseaddr = 0x12345678; /* base address of the device */

		/* tx control */
	/* TRUE | FALSE */
	example.txctrl.txenable = TRUE;						/* enable the transmiter */
	/* DRV_TXBITSPERCLK_1 | DRV_TXBITSPERCLK_2 | DRV_TXBITSPERCLK_3 | DRV_TXBITSPERCLK_4 */
	example.txctrl.txbitsperclk = DRV_TXBITSPERCLK_2;  	/* number of tx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	example.txctrl.txdatainv = FALSE;					/* TX data invert - invert each bit on TX */
	/* DRV_TXODD | DRV_TXEVEN */
	example.txctrl.txparity = DRV_TXEVEN;				/* TX Parity 0 Even 1 Odd */
	/* DRV_PARITY_ENABLED | DRV_PARITY_NOT_EN */
	example.txctrl.txparity_noten = DRV_TXPARITY_ENABLED;	/* TX Parity not enabled - 0 Enabled 1 not enabled */
	/* TRUE | FALSE */
	example.txctrl.txerr = FALSE;						/* TX Error Status - Last read value */ 
	/* TRUE | FALSE */
	example.txctrl.txrdy = TRUE;						/* TX ready for data */
	 
		/* rx control */
	/* TRUE | FALSE */
	example.rxctrl.rxenable = TRUE;						/* enable the reciever */
	/* DRV_RXBITSPERCLK_1 | DRV_RXBITSPERCLK_2 | DRV_RXBITSPERCLK_3 | DRV_RXBITSPERCLK_4 */
	example.rxctrl.rxbitsperclk = DRV_RXBITSPERCLK_2;	/* number of rx bits per sys clock (1-4) */
	/* TRUE | FALSE */
	example.rxctrl.rxdatainv = FALSE;					/* RX data invert - invert each bit on TX */
	/* DRV_RXODD | DRV_RXEVEN */
	example.rxctrl.rxparity = DRV_RXEVEN;				/* RX Parity 0 Even 1 Odd */
	/* DRV_RXPARITY_ENABLED | DRV_RXPARITY_NOT_EN */
	example.rxctrl.rxparity_noten = DRV_RXPARITY_ENABLED;	/* RX Parity not enabled - 0 Enabled 1 not enabled */
	/* TRUE | FALSE */
	example.rxctrl.rxerr = FALSE;						/* RX Error Status - Last value read */ 
	/* TRUE | FALSE */
	example.rxctrl.rxrdy = FALSE;						/* RX has data */

	drvInitDevice(&example);

	/* you must install the drvMainTask for loopback operation */
	task_init("MYTASK", task);
}

