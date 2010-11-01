/* Copyright 2003 Aaron Baranoff                          */
/* Define your registers and their bits and masks in here */
/* FOLLOW the DATASHEET's lead when possible               */


#ifndef DRVREG_H

#define DRVREG_H

/* this register controls transmit - 8 bits R/W (except where noted) */
#define DRV_TXREG	0	

#define	DRV_TXENABLE 		(1<<7)		/* enable the transmiter */
#define DRV_TXBITSPERCLK	(1<<5)      /* number of tx bits per sys clock (1-4) */
#define	DRV_TXBITSPERCLK_1	0
#define	DRV_TXBITSPERCLK_2	1
#define	DRV_TXBITSPERCLK_3	2
#define	DRV_TXBITSPERCLK_4	3
#define DRV_TXDATAINV		(1<<4)		/* TX data invert - invert each bit on TX */
#define DRV_TXPARITY		(1<<3)		/* TX Parity 0 Even 1 Odd */
#define DRV_TXODD			0
#define DRV_TXEVEN			1
#define DRV_TXPARITY_NOTEN 	(1<<2)		/* TX Parity not enabled - 0 Enabled 1 not enabled */
#define DRV_TXPARITY_ENABLED 0
#define DRV_TXPARITY_NOT_EN	 1
#define DRV_TXERR			(1<<1)		/* TX Error Status - read and clear*/ 
#define DRV_TXRDY			(1<<0)		/* TX ready for data */

/* this register is the data to be transmitted */
#define DRV_TXDATA	1	

/* this register controls transmit - 8 bits R/W (except where noted) */
#define DRV_RXREG	2	

#define	DRV_RXENABLE 		(1<<7)		/* enable the reciever */
#define DRV_RXBITSPERCLK	(1<<5)      /* number of rx bits per sys clock (1-4) */
#define	DRV_RXBITSPERCLK_1	0
#define	DRV_RXBITSPERCLK_2	1
#define	DRV_RXBITSPERCLK_3	2
#define	DRV_RXBITSPERCLK_4	3
#define DRV_RXDATAINV		(1<<4)		/* RX data invert - invert each bit on TX */
#define DRV_RXPARITY		(1<<3)		/* RX Parity 0 Even 1 Odd */
#define DRV_RXODD			0
#define DRV_RXEVEN			1
#define DRV_RXPARITY_NOTEN 	(1<<2)		/* RX Parity not enabled - 0 Enabled 1 not enabled */
#define DRV_RXPARITY_ENABLED 0
#define DRV_RXPARITY_NOT_EN	 1
#define DRV_RXERR			(1<<1)		/* RX Error Status - read and clear */ 
#define DRV_RXRDY			(1<<0)		/* RX has data */

/* this register is the data that was recieved data is invalid if DRV_RXRDY is not set */
#define DRV_RXDATA	3	


#endif
