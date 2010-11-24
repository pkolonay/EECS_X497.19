
#ifndef __drvcore_H__
#define __drvcore_H__

#include "..\inc\atmega2560.h"
#include "drvreg.h"


/* CPU frequency */
#define F_CPU 8000000 /* 8MHz */

/* Control-Z is used to control capture of serial port to EEPROM */
#define RECORDING_CONTROL_CHAR 0x1A
/* Control-Y is used to trigger playback of EEPROM */
#define PLAYBACK_CHAR 0x19
/* Control-n dump the number of bytes in the eprom */
#define DUMP_NUMBER_OF_BYTES_CHAR 0x0E
/* Add this to a digit to map into ascii range */
#define MAP_DIGIT_TO_ASCII 0x30

/* Use the first locatino in eeprom to hold a count of the number
   of locations that have been written.
   */
#define EEPROM_DATA_COUNT_ADDR 0

#define TRUE  1
#define FALSE 0


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
    UINT8 	baseaddr; /* base address of the device */
    UINT8	errors;
    UINT8 	dir;	  /* port direction */
    UINT8   pin;	  /* port output    */
    UINT8   data;     /* port input     */
} DRVGPIO, * PDRVGPIO;

typedef struct 
{
    DRVGPIO gpio; 
}  DRVCTRL, * PDRVCTRL;


typedef struct
{
    UINT8    recv_complete_ie;  /* Recv complete interrupt enable */
	UINT8    xmit_complete_ie;  /* Xmit complete interrupt enable */
	UINT8    data_reg_empty_ie; /* Data Register Empty Interrupt Enable */
	UINT8    recv_enable;       /* Enable USART transmitter */
	UINT8    xmit_enable;       /* Enable USART transmitter */
	/* Number of data bits: 0:5-bit,1:6:bit,2:7-bit,3:8-bit,7:9-bit */
    UINT8    number_data_bits;   
	UINT8    RXB8;  /* Receive data bit 8 */
	UINT8    TXB8;  /* Xmit data bit 8 */
	/* Mode select:  0:Asynch, 1:Synch, 2:Reserved, 3:Master SPI */
	UINT8    mode; 
	/* Parity:       0:Disabled, 1:Reserved, 2:Even, 3:Odd */
	UINT8    parity;
	/* Stop bits 0:1-bit, 1:2-bits */
	UINT8    stop_bits; 
	/* Baud rate: */
	UINT16   baud_rate;
} DRVUSARTCTRL, * PDRVUSARTCTRL;


typedef struct {
    UINT8    status;
} DRVUSARTSTAT, * PDRVUSARTSTAT;

typedef struct {
    UINT8    data;
} DRVUSARTDATA, * PDRVUSARTDATA;


typedef struct
{
    UINT16          baseaddr;
    DRVUSARTSTAT    status;
	DRVUSARTCTRL    control;
	DRVUSARTDATA    data;


} DRVUSART, * PDRVUSART;


#define ADDR_MULTIPLIER 1

UINT8 read_pin(UINT16 port, UINT8 pin);
void write_pin(UINT16 port, UINT8 pin, UINT8 value);
void toggle_pin(UINT16 port, UINT8 pin);

void drvWriteEeprom(UINT16 addr, UINT8 data);
UINT8 drvReadEeprom(UINT16 addr);

void delay_mSec();

void timer_init(UINT8);

/**
  * Used to set a bit in a in a given byte at a given address.
  */
void drvSetBit(UINT16,UINT8);

/**
  * Used to clear a bit in a in a given byte at a given address.
  */
void drvClearBit(UINT16,UINT8);

/**
  * Used to test a bit in a in a given byte at a given address.
  */
UINT8 drvTestBit(UINT16, UINT16, UINT8);

void drvUSARTSend(UINT8 data);

void drvUpdateEepromDataCount();

void drv_usart_init(DRVUSART serial_port, UINT16 baseaddr, UINT16 baudrate, UINT8 stop_bits, UINT8 date_bits, UINT8 partiy);

void myitoa(UINT8 myascii[],UINT16 length, UINT16 value);

void drvWriteUint16Reg(const UINT16 base, UINT16 offset, UINT16 value);
#endif /* drvcore */
