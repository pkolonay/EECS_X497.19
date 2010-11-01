/* Copyright 2003 Aaron Baranoff                                */
/* Your porting constants and Macros                            */
/* in this file is where the os/complier dependencies can occur */


#ifndef DRVPORT_H

#define DRVPORT_H


#include "osstuff.h"   /* <-- include OS and types headers here not in each C file */

#define TRUE	1
#define FALSE	0

#define UINT8 	unsigned char
#define INT8	signed char
#define UINT16	unsigned short
#define INT16	signed short
#define UINT32	unsigned int
#define INT32	signed int

#define SWAP /* comment this out is you don't need to bytes swap */ 

/* Do byte swapping - if you want to improve performance and you are bytes swapping 
   use an assemple macro                                                            */
#ifdef SWAP
#define HANDLE_BYTEORDER32(a) ((((a) & 0xff) << 24) | (((a) & 0xff00) << 8) | (((a) & 0xff0000) >> 8) | (((a) >> 24))
#else																	
#define HANDLE_BYTEORDER32(a) (a)
#endif

#ifdef SWAP
#define HANDLE_BYTEORDER16(a) ((((a) & 0xff00) >> 8) | (((a) & 0xff) << 8))
#else																	
#define HANDLE_BYTEORDER16(a) (a)
#endif


/* if each address is how far apart each register is in memory */
#define ADDR_MULTIPLIER	  1

#include "drvport.h"
#include "drvother.h"


#endif
