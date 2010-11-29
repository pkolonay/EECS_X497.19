/*****************************************************************************/
/*                                                                           */
/* Filename: hw_timer.h                                                      */
/* Description:  Add timer/counter definitions as they seem useful.          */
/*                                                                           */
/* EECS_X497.19                                                              */ 
/*                                                                           */
/* Date: 11-08-2010                                                          */
/* Author: Paul Kolonay                                                      */
/*****************************************************************************/

#ifndef __hw_timer_H__
#define __hw_timer_H__


/* Timer/counter 0 prescaler settings */
#define TC0_CK_1    CS00          /* F_CPU/1  No prescale */
#define TC0_CK_8    CS01          /* F_CPU/8              */
#define TC0_CK_64   CS01 | CS00   /* F_CPU/64             */
#define TC0_CK_256  CS02          /* F_CPU/256            */
#define TC0_CK_1024 CS02 | CS00   /* F_CPU/1024           */

/* Timer/counter 1 prescaler settings */
#define TC1_CK_1    CS10          /* F_CPU/1  No prescale */
#define TC1_CK_8    CS11          /* F_CPU/8              */
#define TC1_CK_64   CS11 | CS10   /* F_CPU/64             */
#define TC1_CK_256  CS12          /* F_CPU/256            */
#define TC1_CK_1024 CS12 | CS10   /* F_CPU/1024           */

#endif  /* __hw_timer_H__ */

