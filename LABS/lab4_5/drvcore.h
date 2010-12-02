/*****************************************************************************/
/* Filename: drvcore.h                                                       */
/* Description: For Lab4/5 of EECS_X497.19.                                  */
/* Date: 11-28-2010                                                          */
/* Author: Paul Kolonay                                                      */ 
/*****************************************************************************/

#ifndef __drvcore_H__
#define __drvcore_H__

#include "..\inc\atmega2560.h"
#include "drvreg.h"
#include "..\inc\LightweightRingBuff.h"


#define UINT16 unsigned int
#define UINT8  unsigned char
#define INT16 int
#define INT8  char

/* CPU frequency */
#define F_CPU 8000000 /* 8MHz */

/* Control-Z is used to control capture of serial port to EEPROM */
#define RECORDING_CONTROL_CHAR 0x1A
/* Control-Y is used to trigger playback of EEPROM */
#define PLAYBACK_CHAR 0x19
/* Control-n dump the number of bytes in the eprom */
#define DUMP_NUMBER_OF_BYTES_CHAR 0x0E
/* Backspace character */
#define BACKSPACE_CHAR 0x7f
/* Add this to a digit to map into ascii range */
#define MAP_DIGIT_TO_ASCII 0x30
/* Carriage return/line feed string */
#define CR_LF_STRING "\r\n"
#define CR_CHAR '\r'
#define LF_CHAR '\n'


#define BYTES_STORED_STRING "Bytes stored: "
#define EEPROM_FULL_STRING "WARNING: EEPROM is filled to capacity. No more bytes can be stored.\r\n"



/* Use the first locatino in eeprom to hold a count of the number
   of locations that have been written.
   */
#define EEPROM_DATA_COUNT_ADDR 0
/* Data in EEPROM starts at the third byte */
#define EEPROM_DATA_START_ADDR 2

#define TRUE  1
#define FALSE 0

volatile RingBuff_t rbuff;
volatile UINT16 next_eeprom_address;
volatile UINT16 number_of_bytes_used_in_eeprom;


#define ADDR_MULTIPLIER 1

UINT8 read_pin(UINT16 port, UINT8 pin);
void write_pin(UINT16 port, UINT8 pin, UINT8 value);
void toggle_pin(UINT16 port, UINT8 pin);

UINT8 drvWriteEeprom(UINT16 addr, UINT8 data);
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

void drvUSARTPutChar(UINT8 data);

void drvUpdateEepromDataCount(INT16);
void drvResetEepromDataCount();
UINT16 drvRead16Eeprom(UINT16 addr);

void myitoa(UINT8 myascii[],UINT16 length, UINT16 value);

void drvWriteUint16Reg(const UINT16 base, UINT16 offset, UINT16 value);

void drvUSARTWriteString(const UINT8 *,UINT8);

void drvWriteReg(UINT16 base, UINT16 offset, UINT8 value);
UINT8 drvReadReg(UINT16 base, UINT16 offset);


#endif /* drvcore */
