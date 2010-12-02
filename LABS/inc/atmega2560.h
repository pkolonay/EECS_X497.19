/*****************************************************************************/
/*                                                                           */
/* atmega2560.h - ATMEGA2560 Register Definitions                            */
/*                                                                           */
/* EECS_X497.19                                                              */ 
/*                                                                           */
/* Paul Kolonay                                                              */
/*****************************************************************************/

#ifndef __atmega2560_H__
#define __atmega2560_H__

#define UINT16 unsigned int
#define UINT8  unsigned char


/* sei – enables interrupts */
#define sei() __asm__ __volatile__ ("sei" ::) 
/* cli – disables interrupts */
#define cli() __asm__ __volatile__ ("cli" ::) 

/* base 0 instead of base 1 */
/* vectors in AVR are hardcoded to a function by name */
/* interrupt is disabled at initialization */

/* Timer/Counter0 Overflow */
extern void __vector_23 (void) __attribute__ ((interrupt)); 

/* USART0 Rx Complete */
extern void __vector_25 (void) __attribute__ ((signal));

/* USART0 Data Register Empty */
extern void __vector_26 (void) __attribute__ ((signal));

/* USART0 Tx Complete */
extern void __vector_27 (void) __attribute__ ((signal));

/* Took this directly from the WinAVR eeprom.h file */
#define EEMEM __attribute__((section(".eeprom")))

/*****************************************************************************/
/*                                                                           */
/* Macro for hardware register access.                                       */
/*                                                                           */
/*****************************************************************************/
#define HWREG(x) (*((volatile unsigned int *)(x)))


/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTA) Regsters                                                     */
/*                                                                           */
/*****************************************************************************/
#define PINA        0x20 /* PINA7    |PINA6    |PINA5    |PINA4    |PINA3    |PINA2    |PINA1    |PINA0     */
#define PINA7     (1<<7)    /* R/W */
#define PINA6     (1<<6)    /* R/W */
#define PINA5     (1<<5)    /* R/W */
#define PINA4     (1<<4)    /* R/W */
#define PINA3     (1<<3)    /* R/W */
#define PINA2     (1<<2)    /* R/W */
#define PINA1     (1<<1)    /* R/W */
#define PINA0     (1<<0)    /* R/W */

#define DDRA        0x21 /* DDA7     |DDA6     |DDA5     |DDA4     |DDA3     |DDA2     |DDA1     |DDA0      */
#define DDA7      (1<<7)    /* R/W */
#define DDA6      (1<<6)    /* R/W */
#define DDA5      (1<<5)    /* R/W */
#define DDA4      (1<<4)    /* R/W */
#define DDA3      (1<<3)    /* R/W */
#define DDA2      (1<<2)    /* R/W */
#define DDA1      (1<<1)    /* R/W */
#define DDA0      (1<<0)    /* R/W */

#define PORTA       0x22 /* PORTA7   |PORTA6   |PORTA5   |PORTA4   |PORTA3   |PORTA2   |PORTA1   |PORTA0    */
#define PORTA7    (1<<7)    /* R/W */
#define PORTA6    (1<<6)    /* R/W */
#define PORTA5    (1<<5)    /* R/W */
#define PORTA4    (1<<4)    /* R/W */
#define PORTA3    (1<<3)    /* R/W */
#define PORTA2    (1<<2)    /* R/W */
#define PORTA1    (1<<1)    /* R/W */
#define PORTA0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTB) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINB        0x23 /* PINB7    |PINB6    |PINB5    |PINB4    |PINB3    |PINB2    |PINB1    |PINB0     */
#define PINB7     (1<<7)    /* R/W */
#define PINB6     (1<<6)    /* R/W */
#define PINB5     (1<<5)    /* R/W */
#define PINB4     (1<<4)    /* R/W */
#define PINB3     (1<<3)    /* R/W */
#define PINB2     (1<<2)    /* R/W */
#define PINB1     (1<<1)    /* R/W */
#define PINB0     (1<<0)    /* R/W */

#define DDRB        0x24 /* DDB7     |DDB6     |DDB5     |DDB4     |DDB3     |DDB2     |DDB1     |DDB0      */
#define DDB7      (1<<7)    /* R/W */
#define DDB6      (1<<6)    /* R/W */
#define DDB5      (1<<5)    /* R/W */
#define DDB4      (1<<4)    /* R/W */
#define DDB3      (1<<3)    /* R/W */
#define DDB2      (1<<2)    /* R/W */
#define DDB1      (1<<1)    /* R/W */
#define DDB0      (1<<0)    /* R/W */

#define PORTB       0x25 /* PORTB7   |PORTB6   |PORTB5   |PORTB4   |PORTB3   |PORTB2   |PORTB1   |PORTB0    */
#define PORTB7    (1<<7)    /* R/W */
#define PORTB6    (1<<6)    /* R/W */
#define PORTB5    (1<<5)    /* R/W */
#define PORTB4    (1<<4)    /* R/W */
#define PORTB3    (1<<3)    /* R/W */
#define PORTB2    (1<<2)    /* R/W */
#define PORTB1    (1<<1)    /* R/W */
#define PORTB0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTC) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINC        0x26 /* PINC7    |PINC6    |PINC5    |PINC4    |PINC3    |PINC2    |PINC1    |PINC0     */
#define PINC7     (1<<7)    /* R/W */
#define PINC6     (1<<6)    /* R/W */
#define PINC5     (1<<5)    /* R/W */
#define PINC4     (1<<4)    /* R/W */
#define PINC3     (1<<3)    /* R/W */
#define PINC2     (1<<2)    /* R/W */
#define PINC1     (1<<1)    /* R/W */
#define PINC0     (1<<0)    /* R/W */

#define DDRC        0x27 /* DDC7     |DDC6     |DDC5     |DDC4     |DDC3     |DDC2     |DDC1     |DDC0      */
#define DDC7      (1<<7)    /* R/W */
#define DDC6      (1<<6)    /* R/W */
#define DDC5      (1<<5)    /* R/W */
#define DDC4      (1<<4)    /* R/W */
#define DDC3      (1<<3)    /* R/W */
#define DDC2      (1<<2)    /* R/W */
#define DDC1      (1<<1)    /* R/W */
#define DDC0      (1<<0)    /* R/W */

#define PORTC       0x28 /* PORTC7   |PORTC6   |PORTC5   |PORTC4   |PORTC3   |PORTC2   |PORTC1   |PORTC0    */
#define PORTC7    (1<<7)    /* R/W */
#define PORTC6    (1<<6)    /* R/W */
#define PORTC5    (1<<5)    /* R/W */
#define PORTC4    (1<<4)    /* R/W */
#define PORTC3    (1<<3)    /* R/W */
#define PORTC2    (1<<2)    /* R/W */
#define PORTC1    (1<<1)    /* R/W */
#define PORTC0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTD) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PIND        0x29 /* PIND7    |PIND6    |PIND5    |PIND4    |PIND3    |PIND2    |PIND1    |PIND0     */
#define PIND7     (1<<7)    /* R/W */
#define PIND6     (1<<6)    /* R/W */
#define PIND5     (1<<5)    /* R/W */
#define PIND4     (1<<4)    /* R/W */
#define PIND3     (1<<3)    /* R/W */
#define PIND2     (1<<2)    /* R/W */
#define PIND1     (1<<1)    /* R/W */
#define PIND0     (1<<0)    /* R/W */

#define DDRD        0x2A /* DDD7     |DDD6     |DDD5     |DDD4     |DDD3     |DDD2     |DDD1     |DDD0      */
#define DDD7      (1<<7)    /* R/W */
#define DDD6      (1<<6)    /* R/W */
#define DDD5      (1<<5)    /* R/W */
#define DDD4      (1<<4)    /* R/W */
#define DDD3      (1<<3)    /* R/W */
#define DDD2      (1<<2)    /* R/W */
#define DDD1      (1<<1)    /* R/W */
#define DDD0      (1<<0)    /* R/W */

#define PORTD       0x2B /* PORTD7   |PORTD6   |PORTD5   |PORTD4   |PORTD3   |PORTD2   |PORTD1   |PORTD0    */
#define PORTD7    (1<<7)    /* R/W */
#define PORTD6    (1<<6)    /* R/W */
#define PORTD5    (1<<5)    /* R/W */
#define PORTD4    (1<<4)    /* R/W */
#define PORTD3    (1<<3)    /* R/W */
#define PORTD2    (1<<2)    /* R/W */
#define PORTD1    (1<<1)    /* R/W */
#define PORTD0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTE) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINE        0x2C /* PINE7    |PINE6    |PINE5    |PINE4    |PINE3    |PINE2    |PINE1    |PINE0     */
#define PINE7     (1<<7)    /* R/W */
#define PINE6     (1<<6)    /* R/W */
#define PINE5     (1<<5)    /* R/W */
#define PINE4     (1<<4)    /* R/W */
#define PINE3     (1<<3)    /* R/W */
#define PINE2     (1<<2)    /* R/W */
#define PINE1     (1<<1)    /* R/W */
#define PINE0     (1<<0)    /* R/W */

#define DDRE        0x2D /* DDE7     |DDE6     |DDE5     |DDE4     |DDE3     |DDE2     |DDE1     |DDE0      */
#define DDE7      (1<<7)    /* R/W */
#define DDE6      (1<<6)    /* R/W */
#define DDE5      (1<<5)    /* R/W */
#define DDE4      (1<<4)    /* R/W */
#define DDE3      (1<<3)    /* R/W */
#define DDE2      (1<<2)    /* R/W */
#define DDE1      (1<<1)    /* R/W */
#define DDE0      (1<<0)    /* R/W */

#define PORTE       0x2E /* PORTE7   |PORTE6   |PORTE5   |PORTE4   |PORTE3   |PORTE2   |PORTE1   |PORTE0    */
#define PORTE7    (1<<7)    /* R/W */
#define PORTE6    (1<<6)    /* R/W */
#define PORTE5    (1<<5)    /* R/W */
#define PORTE4    (1<<4)    /* R/W */
#define PORTE3    (1<<3)    /* R/W */
#define PORTE2    (1<<2)    /* R/W */
#define PORTE1    (1<<1)    /* R/W */
#define PORTE0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTF) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINF        0x2F /* PINF7    |PINF6    |PINF5    |PINF4    |PINF3    |PINF2    |PINF1    |PINF0     */
#define PINF7     (1<<7)    /* R/W */
#define PINF6     (1<<6)    /* R/W */
#define PINF5     (1<<5)    /* R/W */
#define PINF4     (1<<4)    /* R/W */
#define PINF3     (1<<3)    /* R/W */
#define PINF2     (1<<2)    /* R/W */
#define PINF1     (1<<1)    /* R/W */
#define PINF0     (1<<0)    /* R/W */

#define DDRF        0x30 /* DDF7     |DDF6     |DDF5     |DDF4     |DDF3     |DDF2     |DDF1     |DDF0      */
#define DDF7      (1<<7)    /* R/W */
#define DDF6      (1<<6)    /* R/W */
#define DDF5      (1<<5)    /* R/W */
#define DDF4      (1<<4)    /* R/W */
#define DDF3      (1<<3)    /* R/W */
#define DDF2      (1<<2)    /* R/W */
#define DDF1      (1<<1)    /* R/W */
#define DDF0      (1<<0)    /* R/W */

#define PORTF       0x31 /* PORTF7   |PORTF6   |PORTF5   |PORTF4   |PORTF3   |PORTF2   |PORTF1   |PORTF0    */
#define PORTF7    (1<<7)    /* R/W */
#define PORTF6    (1<<6)    /* R/W */
#define PORTF5    (1<<5)    /* R/W */
#define PORTF4    (1<<4)    /* R/W */
#define PORTF3    (1<<3)    /* R/W */
#define PORTF2    (1<<2)    /* R/W */
#define PORTF1    (1<<1)    /* R/W */
#define PORTF0    (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTG) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PING        0x32 /* -        |-        |PING5    |PING4    |PING3    |PING2    |PING1    |PING0     */
#define PING5     (1<<5)    
#define PING4     (1<<4)
#define PING3     (1<<3)
#define PING2     (1<<2)
#define PING1     (1<<1)
#define PING0     (1<<0)

#define DDRG        0x33 /* -        |-        |DDG5     |DDG4     |DDG3     |DDG2     |DDG1     |DDG0      */
#define DDG5      (1<<5)
#define DDG4      (1<<4)
#define DDG3      (1<<3)
#define DDG2      (1<<2)
#define DDG1      (1<<1)
#define DDG0      (1<<0)

#define PORTG       0x34 /* -        |-        |PORTG5   |PORTG4   |PORTG3   |PORTG2   |PORTG1   |PORTG0    */
#define PORTG5    (1<<5)
#define PORTG4    (1<<4)
#define PORTG3    (1<<3)
#define PORTG2    (1<<2)
#define PORTG1    (1<<1)
#define PORTG0    (1<<0)

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter1 Interrupt Flag Register                                    */
/*                                                                           */
/*****************************************************************************/
#define TIFR1       0x36 /* -        |-        |ICF1     |-        |OCF1C    |OCF1B    |OCF1A    |TOV1      */
#define ICF1      (1<<5) /* R/W */ /* Input Capture Flag          */
#define OCF1C     (1<<3) /* R/W */ /* Output Compare C Match Flag */
#define OCF1B     (1<<2) /* R/W */ /* Output Compare B Match Flag */
#define OCF1A     (1<<1) /* R/W */ /* Output Compare A Match Flag */
#define TOV1      (1<<0) /* R/W */ /* Overflow Flag               */

#define TIFR3       0x38 /* -        |-        |ICF3     |-        |OCF3C    |OCF3B    |OCF3A    |TOV3      */
#define ICF3      (1<<5) /* R/W */ /* Input Capture Flag          */
#define OCF3C     (1<<3) /* R/W */ /* Output Compare C Match Flag */
#define OCF3B     (1<<2) /* R/W */ /* Output Compare B Match Flag */
#define OCF3A     (1<<1) /* R/W */ /* Output Compare A Match Flag */
#define TOV3      (1<<0) /* R/W */ /* Overflow Flag               */

#define TIFR4       0x39 /* -        |-        |ICF4     |-        |OCF4C    |OCF4B    |OCF4A    |TOV4      */
#define ICF4      (1<<5) /* R/W */ /* Input Capture Flag          */
#define OCF4C     (1<<3) /* R/W */ /* Output Compare C Match Flag */
#define OCF4B     (1<<2) /* R/W */ /* Output Compare B Match Flag */
#define OCF4A     (1<<1) /* R/W */ /* Output Compare A Match Flag */
#define TOV4      (1<<0) /* R/W */ /* Overflow Flag               */

#define TIFR5       0x3A /* -        |-        |ICF5     |-        |OCF5C    |OCF5B    |OCF5A    |TOV5      */
#define ICF5      (1<<5) /* R/W */ /* Input Capture Flag          */
#define OCF5C     (1<<3) /* R/W */ /* Output Compare C Match Flag */
#define OCF5B     (1<<2) /* R/W */ /* Output Compare B Match Flag */
#define OCF5A     (1<<1) /* R/W */ /* Output Compare A Match Flag */
#define TOV5      (1<<0) /* R/W */ /* Overflow Flag               */

#define PCIFR       0x3B /* -        |-        |-        |-        |-        |PCIF2    |PCIF1    |PCIF0     */
#define PCIF2     (1<<2)
#define PCIF1     (1<<1)
#define PCIF0     (1<<0)

#define EIFR        0x3C /* INTF7    |INTF6    |INTF5    |INTF4    |INTF3    |INTF2    |INTF1    |INTF0     */
#define INTF7     (1<<7)
#define INTF6     (1<<6)
#define INTF5     (1<<5)
#define INTF4     (1<<4)
#define INTF3     (1<<3)
#define INTF2     (1<<2)
#define INTF1     (1<<1)
#define INTF0     (1<<0)

#define EIMSK       0x3D /* INT7     |INT6     |INT5     |INT4     |INT3     |INT2     |INT1     |INT0      */
#define INT7      (1<<7)
#define INT6      (1<<6)
#define INT5      (1<<5)
#define INT4      (1<<4)
#define INT3      (1<<3)
#define INT2      (1<<2)
#define INT1      (1<<1)
#define INT0      (1<<0)

#define GPIOR0      0x3E /* General Purpose I/O Register 0                                                  */
#define GPIOR0_7   (1<<7)    /* R/W */
#define GPIOR0_6   (1<<6)    /* R/W */
#define GPIOR0_5   (1<<5)    /* R/W */
#define GPIOR0_4   (1<<4)    /* R/W */
#define GPIOR0_3   (1<<3)    /* R/W */
#define GPIOR0_2   (1<<2)    /* R/W */
#define GPIOR0_1   (1<<1)    /* R/W */
#define GPIOR0_0   (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* EEPROM Registers                                                          */
/*                                                                           */
/*****************************************************************************/
#define EECR        0x3F /* -        |-        |EEPM1    |EEPM0    |EERIE    |EEMPE    |EEPE     |EERE      */
#define EEPM1     (1<<5)    /* R/W */
#define EEPM0     (1<<4)    /* R/W */
#define EERIE     (1<<3)    /* R/W */
#define EEMPE     (1<<2)    /* R/W */
#define EEPE      (1<<1)    /* R/W */
#define EERE      (1<<0)    /* R/W */

#define EEDR        0x40 /* EEPROM Data Register                                                            */
#define EEARL       0x41 /* EEPROM Address Register Low Byte                                                */
#define EEARH       0x42 /* EEPROM Address Register High Byte    
                                           */
/*****************************************************************************/
/*                                                                           */
/* General Timer/Counter Control Register                                    */
/*                                                                           */
/*****************************************************************************/
#define GTCCR       0x43 /* TSM      |-        |-        |-        |-        |-        |PSRASY   |PSRSYNC   */
#define TSM       (1<<7) /* R/W */ /* Timer/Counter Synchronization Mode */
#define PSRASY    (1<<1) /* R/W */ /* Prescaler Reset Timer/Counter2     */
#define PSRSYNC   (1<<0) /* R/W */ /* Prescaler Reset for Synchronous Timer/Counters */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter0 Registers                                                  */
/*                                                                           */
/*****************************************************************************/
/*****************************************************************************/
/*                                                                           */
/* Timer/Counter0 Control Register A                                         */
/*                                                                           */
/*****************************************************************************/
#define TCCR0A      0x44 /* COM0A1   |COM0A0   |COM0B1   |COM0B0   |-        |-        |WGM01    |WGM00     */
#define COM0A1    (1<<7)  /* R/W */ /* Compare Match Output A Mode 1 */
#define COM0A0    (1<<6)  /* R/W */ /* Compare Match Output A Mode 0 */
#define COM0B1    (1<<5)  /* R/W */ /* Compare Match Output B Mode 1 */
#define COM0B0    (1<<4)  /* R/W */ /* Compare Match Output B Mode 0 */
#define WGM01     (1<<1)  /* R/W */ /* Waveform Generation Mode 01 */
#define WGM00     (1<<0)  /* R/W */ /* Waveform Generation Mode 00 */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter0 Control Register B                                         */
/*                                                                           */
/*****************************************************************************/
#define TCCR0B      0x45 /* FOC0A    |FOC0B    |-        |-        |WGM02    |CS02     |CS01     |CS00      */
#define FOC0A     (1<<7)  /* W/O */ /* Force Output Compare A */
#define FOC0B     (1<<6)  /* W/O */ /* Force Output Compare B */
#define WGM02     (1<<3)  /* R/W */
#define CS02      (1<<2)  /* R/W */ /* Clock Select           */
#define CS01      (1<<1)  /* R/W */ /* Clock Select           */
#define CS00      (1<<0)  /* R/W */ /* Clock Select           */


#define TCNT0       0x46 /*  Timer/Counter0 (8 Bit) - R/W                                                   */
#define OCR0A       0x47 /*  Timer/Counter0 Output Compare Register A - R/W                                 */
#define OCR0B       0x48 /*  Timer/Counter0 Output Compare Register B - R/W                                 */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter0 Interrupt Mask Register                                    */
/*                                                                           */
/*****************************************************************************/
#define TIMSK0      0x6E /* -        |-        |-        |-        |-        |OCIE0B   |OCIE0A   |TOIE0     */
#define OCIE0B    (1<<2) /* R/W */ /* Timer/Counter Output Compare Match B Interrupt Enable */
#define OCIE0A    (1<<1) /* R/W */ /* Timer/Counter Output Compare Match A Interrupt Enable */
#define TOIE0     (1<<0) /* R/W */ /* Timer/Counter0 Overflow Interrupt Enable */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter0 Interrupt Flag Register                                    */
/*                                                                           */
/*****************************************************************************/
#define TIFR0       0x35 /* -        |-        |-        |-        |-        |OCF0B    |OCF0A    |TOV0      */
#define OCF0B     (1<<2) /* R/W */ /* Timer/Counter 0 Output Compare B Match Flag */
#define OCF0A     (1<<1) /* R/W */ /* Timer/Counter 0 Output Compare A Match Flag */
#define TOV0      (1<<0) /* R/W */ /* Timer/Counter0 Overflow Flag */



#define GPIOR1      0x4A /* General Purpose I/O Register 1                                                  */
#define GPIOR1_7   (1<<7)    /* R/W */
#define GPIOR1_6   (1<<6)    /* R/W */
#define GPIOR1_5   (1<<5)    /* R/W */
#define GPIOR1_4   (1<<4)    /* R/W */
#define GPIOR1_3   (1<<3)    /* R/W */
#define GPIOR1_2   (1<<2)    /* R/W */
#define GPIOR1_1   (1<<1)    /* R/W */
#define GPIOR1_0   (1<<0)    /* R/W */

#define GPIOR2      0x4B /* General Purpose I/O Register 2                                                  */
#define GPIOR2_7   (1<<7)    /* R/W */
#define GPIOR2_6   (1<<6)    /* R/W */
#define GPIOR2_5   (1<<5)    /* R/W */
#define GPIOR2_4   (1<<4)    /* R/W */
#define GPIOR2_3   (1<<3)    /* R/W */
#define GPIOR2_2   (1<<2)    /* R/W */
#define GPIOR2_1   (1<<1)    /* R/W */
#define GPIOR2_0   (1<<0)    /* R/W */

#define SPCR        0x4C /* SPIE     |SPE      |DORD     |MSTR     |CPOL     |CPHA     |SPR1     |SPR0      */
#define SPIE      (1<<7)
#define SPE       (1<<6)
#define DORD      (1<<5)
#define MSTR      (1<<4)
#define CPOL      (1<<3)
#define CPHA      (1<<2)
#define SPR1      (1<<1)
#define SPR0      (1<<0)

#define SPSR        0x4D /* SPIF     |WCOL     |-        |-        |-        |-        |-        |SPI2X     */
#define SPIF      (1<<7)
#define WCOL      (1<<6)
#define SPI2X     (1<<0)
#define SPDR        0x4E /*  SPI Data Register                                                              */

#define ACSR        0x50 /* ACD      |ACBG     |ACO      |ACI      |ACIE     |ACIC     |ACIS1    |ACIS0     */
#define ACD       (1<<7)
#define ACBG      (1<<6)
#define ACO       (1<<5)
#define ACI       (1<<4)
#define ACIE      (1<<3)
#define ACIC      (1<<2)
#define ACIS1     (1<<1)
#define ACIS0     (1<<0)

#define OCDR        0x51 /* OCDR7    |OCDR6    |OCDR5    |OCDR4    |OCDR3    |OCDR2    |OCDR1    |OCDR0     */
#define OCDR7     (1<<7)
#define OCDR6     (1<<6)
#define OCDR5     (1<<5)
#define OCDR4     (1<<4)
#define OCDR3     (1<<3)
#define OCDR2     (1<<2)
#define OCDR1     (1<<1)
#define OCDR0     (1<<0)

#define SMCR        0x53 /* -        |-        |-        |-        |SM2      |SM1      |SM0      |SE        */
#define SM2       (1<<3)
#define SM1       (1<<2)
#define SM0       (1<<1)
#define SE        (1<<0)

#define MCUSR       0x54 /* -        |-        |-        |JTRF     |WDRF     |BORF     |EXTRF    |PORF      */
#define JTRF      (1<<4)
#define WDRF      (1<<3)
#define BORF      (1<<2)
#define EXTRF     (1<<1)
#define PORF      (1<<0)

#define MCUCR       0x55 /* JTD      |-        |-        |PUD      |-        |-        |IVSEL    |IVCE      */
#define JTD       (1<<7)
#define PUD       (1<<4)
#define IVSEL     (1<<1)
#define IVCE      (1<<0)

#define SPMCSR      0x57 /* SPMIE    |RWWSB    |SIGRD    |RWWSRE   |BLBSET   |PGWRT    |PGERS    |SPMEN     */
#define SPMIE     (1<<7)
#define RWWSB     (1<<6)
#define SIGRD     (1<<5)
#define RWWSRE    (1<<4)
#define BLBSET    (1<<3)
#define PGWRT     (1<<2)
#define PGERS     (1<<1)
#define SPMEN     (1<<0)

#define RAMPZ       0x5B /* -        |-        |-        |-        |-        |-        |RAMPZ1   |RAMPZ0    */
#define RAMPZ1    (1<<1)
#define RAMPZ0    (1<<0)

#define EIND        0x5C /* -        |-        |-        |-        |-        |-        |-        |EIND0     */
#define EIND0     (1<<0)

/* Stack Pointer Low Register */
#define SPL         0x5D /* SP7      |SP6      |SP5      |SP4      |SP3      |SP2      |SP1      |SP0       */
#define SP7       (1<<7)    /* R/W */
#define SP6       (1<<6)    /* R/W */
#define SP5       (1<<5)    /* R/W */
#define SP4       (1<<4)    /* R/W */
#define SP3       (1<<3)    /* R/W */
#define SP2       (1<<2)    /* R/W */
#define SP1       (1<<1)    /* R/W */
#define SP0       (1<<0)    /* R/W */

/* Stack Pointer High  Register */
#define SPH         0x5E /* SP15     |SP14     |SP13     |SP12     |SP11     |SP10     |SP9      |SP8       */
#define SP15      (1<<7)    /* R/W */
#define SP14      (1<<6)    /* R/W */
#define SP13      (1<<5)    /* R/W */
#define SP12      (1<<4)    /* R/W */
#define SP11      (1<<3)    /* R/W */
#define SP10      (1<<2)    /* R/W */
#define SP9       (1<<1)    /* R/W */
#define SP8       (1<<0)    /* R/W */

/* AVR Status Register */
#define SREG        0x5F     /* I        |T        |H        |S        |V        |N        |Z        |C         */
#define I         (1<<7)    /* R/W - GIE               */
#define T         (1<<6)    /* R/W - Bit copy storage  */
#define H         (1<<5)    /* R/W - Half Carry        */
#define S         (1<<4)    /* R/W - Sign              */
#define V         (1<<3)    /* R/W - Overflow          */
#define Z         (1<<1)    /* R/W - Negative          */
#define C         (1<<0)    /* R/W - Zero              */

#define WDTCSR      0x60 /* WDIF     |WDIE     |WDP3     |WDCE     |WDE      |WDP2     |WDP1     |WDP0      */
#define WDIF      (1<<7)    /* R/W */
#define WDIE      (1<<6)    /* R/W */
#define WDP3      (1<<5)    /* R/W */
#define WDCE      (1<<4)    /* R/W */
#define WDE       (1<<3)    /* R/W */
#define WDP2      (1<<2)    /* R/W */
#define WDP1      (1<<1)    /* R/W */
#define WDP0      (1<<0)    /* R/W */

#define CLKPR       0x61 /* CLKPCE   |-        |-        |-        |CLKPS3   |CLKPS2   |CLKPS1   |CLKPS0    */
#define CLKPCE    (1<<7)
#define CLKPS3    (1<<3)
#define CLKPS2    (1<<2)
#define CLKPS1    (1<<1)
#define CLKPS0    (1<<0)

#define PRR0        0x64 /* PRTWI    |PRTIM2   |PRTIM0   |-        |PRTIM1   |PRSPI    |PRUSART0 |PRADC     */
#define PRTWI     (1<<7)
#define PRTIM2    (1<<6)
#define PRTIM0    (1<<5)
#define PRTIM1    (1<<3)
#define PRSPI     (1<<2)
#define PRUSART0  (1<<1)
#define PRADC     (1<<0)

#define PRR1        0x65 /* -        |-        |PRTIM5   |PRTIM4   |PRTIM3   |PRUSART3 |PRUSART2 |PRUSART1  */
#define PRTIM5    (1<<5)
#define PRTIM4    (1<<4)
#define PRTIM3    (1<<3)
#define PRUSART3  (1<<2)
#define PRUSART2  (1<<1)
#define PRUSART1  (1<<0)

#define OSCCAL      0x66 /* Oscillator Calibration Register                                                 */

#define PCICR       0x68 /* -        |-        |-        |-        |-        |PCIE2    |PCIE1    |PCIE0     */
#define PCIE2     (1<<2)
#define PCIE1     (1<<1)
#define PCIE0     (1<<0)

#define EICRA       0x69 /* ISC31    |ISC30    |ISC21    |ISC20    |ISC11    |ISC10    |ISC01    |ISC00     */
#define ISC31     (1<<7)
#define ISC30     (1<<6)
#define ISC21     (1<<5)
#define ISC20     (1<<4)
#define ISC11     (1<<3)
#define ISC10     (1<<2)
#define ISC01     (1<<1)
#define ISC00     (1<<0)

#define EICRB       0x6A /* ISC71    |ISC70    |ISC61    |ISC60    |ISC51    |ISC50    |ISC41    |ISC40     */
#define ISC71     (1<<7)
#define ISC70     (1<<6)
#define ISC61     (1<<5)
#define ISC60     (1<<4)
#define ISC51     (1<<3)
#define ISC50     (1<<2)
#define ISC41     (1<<1)
#define ISC40     (1<<0)

#define PCMSK0      0x6B /* PCINT7   |PCINT6   |PCINT5   |PCINT4   |PCINT3   |PCINT2   |PCINT1   |PCINT0    */
#define PCINT7    (1<<7)
#define PCINT6    (1<<6)
#define PCINT5    (1<<5)
#define PCINT4    (1<<4)
#define PCINT3    (1<<3)
#define PCINT2    (1<<2)
#define PCINT1    (1<<1)
#define PCINT0    (1<<0)

#define PCMSK1      0x6C /* PCINT15  |PCINT14  |PCINT13  |PCINT12  |PCINT11  |PCINT10  |PCINT9   |PCINT8    */
#define PCINT15   (1<<7)
#define PCINT14   (1<<6)
#define PCINT13   (1<<5)
#define PCINT12   (1<<4)
#define PCINT11   (1<<3)
#define PCINT10   (1<<2)
#define PCINT9    (1<<1)
#define PCINT8    (1<<0)

#define PCMSK2      0x6D /* PCINT23  |PCINT22  |PCINT21  |PCINT20  |PCINT19  |PCINT18  |PCINT17  |PCINT16   */
#define PCINT23   (1<<7)
#define PCINT22   (1<<6)
#define PCINT21   (1<<5)
#define PCINT20   (1<<4)
#define PCINT19   (1<<3)
#define PCINT18   (1<<2)
#define PCINT17   (1<<1)
#define PCINT16   (1<<0)

#define TIMSK1      0x6F /* -        |-        |ICIE1    |-        |OCIE1C   |OCIE1B   |OCIE1A   |TOIE1     */
#define ICIE1     (1<<5)
#define OCIE1C    (1<<3)
#define OCIE1B    (1<<2)
#define OCIE1A    (1<<1)
#define TOIE1     (1<<0)


#define TIMSK3      0x71 /* -        |-        |ICIE3    |-        |OCIE3C   |OCIE3B   |OCIE3A   |TOIE3     */
#define ICIE3     (1<<5)
#define OCIE3C    (1<<3)
#define OCIE3B    (1<<2)
#define OCIE3A    (1<<1)
#define TOIE3     (1<<0)

#define TIMSK4      0x72 /* -        |-        |ICIE4    |-        |OCIE4C   |OCIE4B   |OCIE4A   |TOIE4     */
#define ICIE4     (1<<5)
#define OCIE4C    (1<<3)
#define OCIE4B    (1<<2)
#define OCIE4A    (1<<1)
#define TOIE4     (1<<0)

#define TIMSK5      0x73 /* -        |-        |ICIE5    |-        |OCIE5C   |OCIE5B   |OCIE5A   |TOIE5     */
#define ICIE5     (1<<5)
#define OCIE5C    (1<<3)
#define OCIE5B    (1<<2)
#define OCIE5A    (1<<1)
#define TOIE5     (1<<0)

/* External Memory Control Register A */
#define XMCRA       0x74 /* SRE      |SRL2     |SRL1     |SRL0     |SRW11    |SRW10    |SRW01    |SRW00     */
#define SRE       (1<<7)    /* R/W */
#define SRL2      (1<<6)    /* R/W */
#define SRL1      (1<<5)    /* R/W */
#define SRL0      (1<<4)    /* R/W */
#define SRW11     (1<<3)    /* R/W */
#define SRW10     (1<<2)    /* R/W */
#define SRW01     (1<<1)    /* R/W */
#define SRW00     (1<<0)    /* R/W */

#define XMCRB       0x75 /* XMBK     |-        |-        |-        |-        |XMM2     |XMM1     |XMM0      */
#define XMBK      (1<<7)
#define XMM2      (1<<2)
#define XMM1      (1<<1)
#define XMM0      (1<<0)
#define ADCL        0x78 /* ADC Data Register Low byte                                                      */
#define ADCH        0x79 /* ADC Data Register High byte                                                     */

#define ADCSRA      0x7A /* ADEN     |ADSC     |ADATE    |ADIF     |ADIE     |ADPS2    |ADPS1    |ADPS0     */
#define ADEN      (1<<7)
#define ADSC      (1<<6)
#define ADATE     (1<<5)
#define ADIF      (1<<4)
#define ADIE      (1<<3)
#define ADPS2     (1<<2)
#define ADPS1     (1<<1)
#define ADPS0     (1<<0)

#define ADCSRB      0x7B /* -        |ACME     |-        |-        |MUX5     |ADTS2    |ADTS1    |ADTS0     */
#define ACME      (1<<6)
#define MUX5      (1<<3)
#define ADTS2     (1<<2)
#define ADTS1     (1<<1)
#define ADTS0     (1<<0)

#define ADMUX       0x7C /* REFS1    |REFS0    |ADLAR    |MUX4     |MUX3     |MUX2     |MUX1     |MUX0      */
#define REFS1     (1<<7)
#define REFS0     (1<<6)
#define ADLAR     (1<<5)
#define MUX4      (1<<4)
#define MUX3      (1<<3)
#define MUX2      (1<<2)
#define MUX1      (1<<1)
#define MUX0      (1<<0)

#define DIDR2       0x7D /* ADC15D   |ADC14D   |ADC13D   |ADC12D   |ADC11D   |ADC10D   |ADC9D    |ADC8D     */
#define ADC15D    (1<<7)
#define ADC14D    (1<<6)
#define ADC13D    (1<<5)
#define ADC12D    (1<<4)
#define ADC11D    (1<<3)
#define ADC10D    (1<<2)
#define ADC9D     (1<<1)
#define ADC8D     (1<<0)

#define DIDR0       0x7E /* ADC7D    |ADC6D    |ADC5D    |ADC4D    |ADC3D    |ADC2D    |ADC1D    |ADC0D     */
#define ADC7D     (1<<7)
#define ADC6D     (1<<6)
#define ADC5D     (1<<5)
#define ADC4D     (1<<4)
#define ADC3D     (1<<3)
#define ADC2D     (1<<2)
#define ADC1D     (1<<1)
#define ADC0D     (1<<0)

#define DIDR1       0x7F /* -        |-        |-        |-        |-        |-        |AIN1D    |AIN0D     */
#define AIN1D     (1<<1)
#define AIN0D     (1<<0)

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter1  Registers                                                 */
/*                                                                           */
/*****************************************************************************/
/*****************************************************************************/
/*                                                                           */
/* Timer/Counter 1 Control Register A                                        */
/*                                                                           */
/*****************************************************************************/
#define TCCR1A      0x80 /* COM1A1   |COM1A0   |COM1B1   |COM1B0   |COM1C1   |COM1C0   |WGM11    |WGM10     */
#define COM1A1    (1<<7)    /* R/W */
#define COM1A0    (1<<6)    /* R/W */
#define COM1B1    (1<<5)    /* R/W */
#define COM1B0    (1<<4)    /* R/W */
#define COM1C1    (1<<3)    /* R/W */
#define COM1C0    (1<<2)    /* R/W */
#define WGM11     (1<<1)    /* R/W */
#define WGM10     (1<<0)    /* R/W */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter 1 Control Register B                                        */
/*                                                                           */
/*****************************************************************************/
#define TCCR1B      0x81 /* ICNC1    |ICES1    |-        |WGM13    |WGM12    |CS12     |CS11     |CS10      */
#define ICNC1     (1<<7)
#define ICES1     (1<<6)
#define WGM13     (1<<4)
#define WGM12     (1<<3)
#define CS12      (1<<2)
#define CS11      (1<<1)
#define CS10      (1<<0)

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter 1 Control Register C                                        */
/*                                                                           */
/*****************************************************************************/
#define TCCR1C      0x82 /* FOC1A    |FOC1B    |FOC1C    |-        |-        |-        |-        |-         */
#define FOC1A     (1<<7)
#define FOC1B     (1<<6)
#define FOC1C     (1<<5)

#define TCNT1L      0x84 /* Timer/Counter1 - Counter Register Low Byte                                      */
#define TCNT1H      0x85 /* Timer/Counter1 - Counter Register High Byte                                     */
#define ICR1L       0x86 /* Timer/Counter1 - Input Capture Register Low Byte                                */
#define ICR1H       0x87 /* Timer/Counter1 - Input Capture Register High Byte                               */
#define OCR1AL      0x88 /* Timer/Counter1 - Output Compare Register A Low Byte                             */
#define OCR1AH      0x89 /* Timer/Counter1 - Output Compare Register A High Byte                            */
#define OCR1BL      0x8A /* Timer/Counter1 - Output Compare Register B Low Byte                             */
#define OCR1BH      0x8B /* Timer/Counter1 - Output Compare Register B High Byte                            */
#define OCR1CL      0x8C /* Timer/Counter1 -Output Compare Register C Low Byte                              */
#define OCR1CH      0x8D /* Timer/Counter1 -Output Compare Register C High Byte                             */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter3  Registers                                                 */
/*                                                                           */
/*****************************************************************************/
#define TCCR3A      0x90 /* COM3A1   |COM3A0   |COM3B1   |COM3B0   |COM3C1   |COM3C0   |WGM31    |WGM30     */
#define COM3A1    (1<<7)    /* R/W */
#define COM3A0    (1<<6)    /* R/W */
#define COM3B1    (1<<5)    /* R/W */
#define COM3B0    (1<<4)    /* R/W */
#define COM3C1    (1<<3)    /* R/W */
#define COM3C0    (1<<2)    /* R/W */
#define WGM31     (1<<1)    /* R/W */
#define WGM30     (1<<0)    /* R/W */

#define TCCR3B      0x91 /* ICNC3    |ICES3    |-        |WGM33    |WGM32    |CS32     |CS31     |CS30      */
#define ICNC3     (1<<7)
#define ICES3     (1<<6)
#define WGM33     (1<<4)
#define WGM32     (1<<3)
#define CS32      (1<<2)
#define CS31      (1<<1)
#define CS30      (1<<0)

#define TCCR3C      0x92 /* FOC3A    |FOC3B    |FOC3C    |-        |-        |-        |-        |-         */
#define FOC3A     (1<<7)
#define FOC3B     (1<<6)
#define FOC3C     (1<<5)
#define TCNT3L      0x94 /* Timer/Counter3 - Counter Register Low Byte                                      */
#define TCNT3H      0x95 /* Timer/Counter3 - Counter Register High Byte                                     */
#define ICR3L       0x96 /* Timer/Counter3 - Input Capture Register Low Byte                                */
#define ICR3H       0x97 /* Timer/Counter3 - Input Capture Register High Byte                               */
#define OCR3AL      0x98 /* Timer/Counter3 - Output Compare Register A Low Byte                             */
#define OCR3AH      0x99 /* Timer/Counter3 - Output Compare Register A High Byte                            */
#define OCR3BL      0x9A /* Timer/Counter3 - Output Compare Register B Low Byte                             */
#define OCR3BH      0x9B /* Timer/Counter3 - Output Compare Register B High Byte                            */
#define OCR3CL      0x9C /* Timer/Counter3 -Output Compare Register C Low Byte                              */
#define OCR3CH      0x9D /* Timer/Counter3 -Output Compare Register C High Byte                             */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter4 Registers                                                  */
/*                                                                           */
/*****************************************************************************/
#define TCCR4A      0xA0 /* COM4A1   |COM4A0   |COM4B1   |COM4B0   |COM4C1   |COM4C0   |WGM41    |WGM40     */
#define COM4A1    (1<<7)    /* R/W */
#define COM4A0    (1<<6)    /* R/W */
#define COM4B1    (1<<5)    /* R/W */
#define COM4B0    (1<<4)    /* R/W */
#define COM4C1    (1<<3)    /* R/W */
#define COM4C0    (1<<2)    /* R/W */
#define WGM41     (1<<1)    /* R/W */
#define WGM40     (1<<0)    /* R/W */

#define TCCR4B      0xA1 /* ICNC4    |ICES4    |-        |WGM43    |WGM42    |CS42     |CS41     |CS40      */
#define ICNC4     (1<<7)
#define ICES4     (1<<6)
#define WGM43     (1<<4)
#define WGM42     (1<<3)
#define CS42      (1<<2)
#define CS41      (1<<1)
#define CS40      (1<<0)

#define TCCR4C      0xA2 /* FOC4A    |FOC4B    |FOC4C    |-        |-        |-        |-        |-         */
#define FOC4A     (1<<7)
#define FOC4B     (1<<6)
#define FOC4C     (1<<5)
#define TCNT4L      0xA4 /* Timer/Counter4 - Counter Register Low Byte                                      */
#define TCNT4H      0xA5 /* Timer/Counter4 - Counter Register High Byte                                     */
#define ICR4L       0xA6 /* Timer/Counter4 - Input Capture Register Low Byte                                */
#define ICR4H       0xA7 /* Timer/Counter4 - Input Capture Register High Byte                               */
#define OCR4AL      0xA8 /* Timer/Counter4 - Output Compare Register A Low Byte                             */
#define OCR4AH      0xA9 /* Timer/Counter4 - Output Compare Register A High Byte                            */
#define OCR4BL      0xAA /* Timer/Counter4 - Output Compare Register B Low Byte                             */
#define OCR4BH      0xAB /* Timer/Counter4 - Output Compare Register B High Byte                            */
#define OCR4CL      0xAC /* Timer/Counter4 -Output Compare Register C Low Byte                              */
#define OCR4CH      0xAD /* Timer/Counter4 -Output Compare Register C High Byte                             */

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter2 Registers                                                  */
/*                                                                           */
/*****************************************************************************/
/* Timer/Counter2 Control Register A                                         */
#define TCCR2A      0xB0 /* COM2A1   |COM2A0   |COM2B1   |COM2B0   |-        |-        |WGM21    |WGM20     */
#define COM2A1    (1<<7) /* R/W */ /* Compare Match Output A Mode 1 */
#define COM2A0    (1<<6) /* R/W */ /* Compare Match Output A Mode 0 */
#define COM2B1    (1<<5) /* R/W */ /* Compare Match Output B Mode 1 */
#define COM2B0    (1<<4) /* R/W */ /* Compare Match Output B Mode 0 */
#define WGM21     (1<<1) /* R/W */ /* Waveform Generation Mode 21   */
#define WGM20     (1<<0) /* R/W */ /* Waveform Generation Mode 20   */


/*****************************************************************************/
/*                                                                           */
/* Timer/Counter 2   Control Register B                                      */
/*                                                                           */
/*****************************************************************************/
#define TCCR2B      0xB1 /* FOC2A    |FOC2B    |-        |-        |WGM22    |CS22     |CS21     |CS20      */
#define FOC2A     (1<<7) /* W/O */ /* Force Output Compare A */
#define FOC2B     (1<<6) /* W/O */ /* Force Output Compare B */
#define WGM22     (1<<3) /* R/W */ /* Waveform Generation Mode 22   */
#define CS22      (1<<2) /* R/W */ /* Clock Select 22 */
#define CS21      (1<<1) /* R/W */ /* Clock Select 21 */
#define CS20      (1<<0) /* R/W */ /* Clock Select 20 */

#define TCNT2       0xB2 /*  Timer/Counter2 (8 Bit)                                                         */
#define TCNT27    (1<<7) /* R/W */
#define TCNT26    (1<<6) /* R/W */
#define TCNT25    (1<<5) /* R/W */
#define TCNT24    (1<<4) /* R/W */
#define TCNT23    (1<<3) /* R/W */
#define TCNT22    (1<<2) /* R/W */
#define TCNT21    (1<<1) /* R/W */
#define TCNT20    (1<<0) /* R/W */

#define OCR2A       0xB3 /*  Timer/Counter2 Output Compare Register A                                       */
#define OCR2A7    (1<<7) /* R/W */
#define OCR2A6    (1<<6) /* R/W */
#define OCR2A5    (1<<5) /* R/W */
#define OCR2A4    (1<<4) /* R/W */
#define OCR2A3    (1<<3) /* R/W */
#define OCR2A2    (1<<2) /* R/W */
#define OCR2A1    (1<<1) /* R/W */
#define OCR2A0    (1<<0) /* R/W */

#define OCR2B       0xB4 /*  Timer/Counter2 Output Compare Register B                                       */
#define OCR2B7    (1<<7) /* R/W */
#define OCR2B6    (1<<6) /* R/W */
#define OCR2B5    (1<<5) /* R/W */
#define OCR2B4    (1<<4) /* R/W */
#define OCR2B3    (1<<3) /* R/W */
#define OCR2B2    (1<<2) /* R/W */
#define OCR2B1    (1<<1) /* R/W */
#define OCR2B0    (1<<0) /* R/W */

#define ASSR        0xB6 /* -        |EXCLK    |AS2      |TCN2UB   |OCR2AUB  |OCR2BUB  |TCR2AUB  |TCR2BUB   */
#define EXCLK     (1<<6) /* R/W */ /* Enable External Clock Input */
#define AS2       (1<<5) /* R/W */ /* Asynchronous Timer/Counter2 */
#define TCN2UB    (1<<4) /* R/O */ /* Update Busy */
#define OCR2AUB   (1<<3) /* R/O */ /* A Output Compare Register2 Update Busy */
#define OCR2BUB   (1<<2) /* R/O */ /* B Output Compare Register2 Update Busy */
#define TCR2AUB   (1<<1) /* R/O */ /* A Control Register2 Update Busy */
#define TCR2BUB   (1<<0) /* R/O */ /* B Control Register2 Update Busy */

#define TIMSK2      0x70 /* -        |-        |-        |-        |-        |OCIE2B   |OCIE2A   |TOIE2     */
#define OCIE2B    (1<<2) /* R/W */ /* Output Compare Match B Interrupt Enable */
#define OCIE2A    (1<<1) /* R/W */ /* Output Compare Match A Interrupt Enable */
#define TOIE2     (1<<0) /* R/W */ /* Overflow Interrupt Enable */

#define TIFR2       0x37 /* -        |-        |-        |-        |-        |OCF2B    |OCF2A    |TOV2      */
#define OCF2B     (1<<2) /* R/W */ /* Output Compare Flag B */
#define OCF2A     (1<<1) /* R/W */ /* Output Compare Flag A */
#define TOV2      (1<<0) /* R/W */ /* Overflow Flag         */

/*****************************************************************************/
/*                                                                           */
/* 2-wire Serial Interface   Registers                                       */
/*                                                                           */
/*****************************************************************************/
#define TWBR        0xB8 /* 2-wire Serial Interface Bit Rate Register                                       */
#define TWBR7     (1<<7) /* R/W */
#define TWBR6     (1<<6) /* R/W */
#define TWBR5     (1<<5) /* R/W */
#define TWBR4     (1<<4) /* R/W */
#define TWBR3     (1<<3) /* R/W */
#define TWBR2     (1<<2) /* R/W */
#define TWBR1     (1<<1) /* R/W */
#define TWBR0     (1<<0) /* R/W */

#define TWCR        0xBC /* TWINT    |TWEA     |TWSTA    |TWSTO    |TWWC     |TWEN     |-        |TWIE      */
#define TWINT     (1<<7) /* R/W */ /* Interrupt Flag */
#define TWEA      (1<<6) /* R/W */ /* Enable Acknowledge Bit */
#define TWSTA     (1<<5) /* R/W */ /* START Condition Bit */
#define TWSTO     (1<<4) /* R/W */ /* STOP Condition Bit */
#define TWWC      (1<<3) /* R/O */ /* Write Collision Flag */
#define TWEN      (1<<2) /* R/W */ /* Enable Bit */
#define TWIE      (1<<0) /* R/W */ /* Interrupt Enable */

#define TWSR        0xB9 /* TWS7     |TWS6     |TWS5     |TWS4     |TWS3     |-        |TWPS1    |TWPS0     */
#define TWS7      (1<<7) /* R/O */ /* Status */
#define TWS6      (1<<6) /* R/O */ /* Status */
#define TWS5      (1<<5) /* R/O */ /* Status */
#define TWS4      (1<<4) /* R/O */ /* Status */
#define TWS3      (1<<3) /* R/O */ /* Status */
#define TWPS1     (1<<1) /* R/W */ /* Prescaler Bit1 */
#define TWPS0     (1<<0) /* R/W */ /* Prescaler Bit0 */

#define TWAR        0xBA /* TWA6     |TWA5     |TWA4     |TWA3     |TWA2     |TWA1     |TWA0     |TWGCE     */
#define TWA6      (1<<7)
#define TWA5      (1<<6)
#define TWA4      (1<<5)
#define TWA3      (1<<4)
#define TWA2      (1<<3)
#define TWA1      (1<<2)
#define TWA0      (1<<1)
#define TWGCE     (1<<0)
#define TWDR        0xBB /*  2-wire Serial Interface Data Register                                          */


#define TWAMR       0xBD /* TWAM6    |TWAM5    |TWAM4    |TWAM3    |TWAM2    |TWAM1    |TWAM0    |-         */
#define TWAM6     (1<<7)
#define TWAM5     (1<<6)
#define TWAM4     (1<<5)
#define TWAM3     (1<<4)
#define TWAM2     (1<<3)
#define TWAM1     (1<<2)
#define TWAM0     (1<<1)

/*****************************************************************************/
/*                                                                           */
/* USART0 Registers                                                          */
/*                                                                           */
/*****************************************************************************/
/* USART Control and Status Register A */
#define UCSR0A      0xC0 /* RXC0     |TXC0     |UDRE0    |FE0      |DOR0     |UPE0     |U2X0     |MPCM0     */
#define RXC0      (1<<7)    /* R/W */ /* Receive Complete    */
#define TXC0      (1<<6)    /* R/W */ /* Transmit Complete   */
#define UDRE0     (1<<5)    /* R/W */ /* Data Register Empty */
#define FE0       (1<<4)    /* R/W */ /* Frame Error         */
#define DOR0      (1<<3)    /* R/W */ /* Data Overrun        */
#define UPE0      (1<<2)    /* R/W */ /* Parity Error        */
#define U2X0      (1<<1)    /* R/W */ /* Double Transmission Speed */
#define MPCM0     (1<<0)    /* R/W */ /* Multi-processor Communication Mode */

/* USART Control and Status Register B */
#define UCSR0B      0xC1 /* RXCIE0   |TXCIE0   |UDRIE0   |RXEN0    |TXEN0    |UCSZ02   |RXB80    |TXB80     */
#define RXCIE0    (1<<7)    /* R/W */ /* RX Complete Interrupt Enable */
#define TXCIE0    (1<<6)    /* R/W */ /* TX Complete Interrupt Enable */
#define UDRIE0    (1<<5)    /* R/W */ /* Data Register Empty Interrupt Enable */
#define RXEN0     (1<<4)    /* R/W */ /* Receiver Enable */
#define TXEN0     (1<<3)    /* R/W */ /* Transmitter Enable */
#define UCSZ02    (1<<2)    /* R/W */ /* Character Size */
#define RXB80     (1<<1)    /* R/W */ /* Receive Data Bit 8 */
#define TXB80     (1<<0)    /* R/W */ /* Transmit Data Bit 8 */                    

/* USART Control and Status Register C */
#define UCSR0C      0xC2 /* UMSEL01  |UMSEL00  |UPM01    |UPM00    |USBS0    |UCSZ01   |UCSZ00   |UCPOL0    */
#define UMSEL01   (1<<7)    /* R/W */ /* Mode Select 01 */
#define UMSEL00   (1<<6)    /* R/W */ /* Mode Select 00 */
#define UPM01     (1<<5)    /* R/W */ /* Parity Mode 01 */
#define UPM00     (1<<4)    /* R/W */ /* Parity Mode 00 */
#define USBS0     (1<<3)    /* R/W */ /* Stop Bit Select */
#define UCSZ01    (1<<2)    /* R/W */ /* Character Size 01 */
#define UCSZ00    (1<<1)    /* R/W */ /* Character Size 00 */
#define UCPOL0    (1<<0)    /* R/W */ /* Clock Polarity */    

/* Baud Rate Registers */
#define UBRR0L      0xC4 /* USART0 Baud Rate Register Low Byte                                             */
#define UBRR0L7   (1<<7)    /* R/W */
#define UBRR0L6   (1<<6)    /* R/W */
#define UBRR0L5   (1<<5)    /* R/W */
#define UBRR0L4   (1<<4)    /* R/W */
#define UBRR0L3   (1<<3)    /* R/W */
#define UBRR0L2   (1<<2)    /* R/W */
#define UBRR0L1   (1<<1)    /* R/W */
#define UBRR0L0   (1<<0)    /* R/W */

#define UBRR0H      0xC5 /* USART0 Baud Rate Register High Byte                                             */
#define UBRR0H3   (1<<3)    /* R/W */
#define UBRR0H2   (1<<2)    /* R/W */
#define UBRR0H1   (1<<1)    /* R/W */
#define UBRR0H0   (1<<0)    /* R/W */


#define UDR0        0xC6 /*  USART0 I/O Data Register                                                       */
#define UDR07     (1<<7)    /* R/W/ */
#define UDR06     (1<<7)    /* R/W/ */
#define UDR05     (1<<7)    /* R/W/ */
#define UDR04     (1<<7)    /* R/W/ */
#define UDR03     (1<<7)    /* R/W/ */
#define UDR02     (1<<7)    /* R/W/ */
#define UDR01     (1<<7)    /* R/W/ */
#define UDR00     (1<<7)    /* R/W/ */

/*****************************************************************************/
/*                                                                           */
/* USART1 Registers                                                          */
/*                                                                           */
/*****************************************************************************/
#define UCSR1A      0xC8 /* RXC1     |TXC1     |UDRE1    |FE1      |DOR1     |UPE1     |U2X1     |MPCM1     */
#define RXC1      (1<<7)     /* R/W */ /* Receive Complete    */               
#define TXC1      (1<<6)     /* R/W */ /* Transmit Complete   */               
#define UDRE1     (1<<5)     /* R/W */ /* Data Register Empty */               
#define FE1       (1<<4)     /* R/W */ /* Frame Error         */               
#define DOR1      (1<<3)     /* R/W */ /* Data Overrun        */               
#define UPE1      (1<<2)     /* R/W */ /* Parity Error        */               
#define U2X1      (1<<1)     /* R/W */ /* Double Transmission Speed */         
#define MPCM1     (1<<0)     /* R/W */ /* Multi-processor Communication Mode */

/*****************************************************************************/
/*                                                                           */
/* USART2 Registers                                                          */
/*                                                                           */
/*****************************************************************************/
#define UCSR1B      0xC9 /* RXCIE1   |TXCIE1   |UDRIE1   |RXEN1    |TXEN1    |UCSZ12   |RXB81    |TXB81     */
#define RXCIE1    (1<<7)    /* R/W */  /* RX Complete Interrupt Enable */           
#define TXCIE1    (1<<6)    /* R/W */  /* TX Complete Interrupt Enable */           
#define UDRIE1    (1<<5)    /* R/W */  /* Data Register Empty Interrupt Enable */   
#define RXEN1     (1<<4)    /* R/W */  /* Receiver Enable */                        
#define TXEN1     (1<<3)    /* R/W */  /* Transmitter Enable */                     
#define UCSZ12    (1<<2)    /* R/W */  /* Character Size */                         
#define RXB81     (1<<1)    /* R/W */  /* Receive Data Bit 8 */                     
#define TXB81     (1<<0)    /* R/W */  /* Transmit Data Bit 8 */                    

#define UCSR1C      0xCA /* UMSEL11  |UMSEL10  |UPM11    |UPM10    |USBS1    |UCSZ11   |UCSZ10   |UCPOL1    */
#define UMSEL11   (1<<7)    /* R/W */  /* Mode Select 01 */    
#define UMSEL10   (1<<6)    /* R/W */  /* Mode Select 00 */    
#define UPM11     (1<<5)    /* R/W */  /* Parity Mode 01 */    
#define UPM10     (1<<4)    /* R/W */  /* Parity Mode 00 */    
#define USBS1     (1<<3)    /* R/W */  /* Stop Bit Select */   
#define UCSZ11    (1<<2)    /* R/W */  /* Character Size 01 */ 
#define UCSZ10    (1<<1)    /* R/W */  /* Character Size 00 */ 
#define UCPOL1    (1<<0)    /* R/W */  /* Clock Polarity */    

#define UBRR1L      0xCC /*  USART1 Baud Rate Register Low Byte                                             */
#define UBRR1L7   (1<<7)    /* R/W */
#define UBRR1L6   (1<<6)    /* R/W */
#define UBRR1L5   (1<<5)    /* R/W */
#define UBRR1L4   (1<<4)    /* R/W */
#define UBRR1L3   (1<<3)    /* R/W */
#define UBRR1L2   (1<<2)    /* R/W */
#define UBRR1L1   (1<<1)    /* R/W */
#define UBRR1L0   (1<<0)    /* R/W */

#define UBRR1H      0xCD /* USART1 Baud Rate Register High Byte                                             */
#define UBRR1H3   (1<<3)    /* R/W */
#define UBRR1H2   (1<<2)    /* R/W */
#define UBRR1H1   (1<<1)    /* R/W */
#define UBRR1H0   (1<<0)    /* R/W */

#define UDR1        0xCE /*  USART1 I/O Data Register                                                       */
#define UDR17   (1<<7)    /* R/W */
#define UDR16   (1<<6)    /* R/W */
#define UDR15   (1<<5)    /* R/W */
#define UDR14   (1<<4)    /* R/W */
#define UDR13   (1<<3)    /* R/W */
#define UDR12   (1<<2)    /* R/W */
#define UDR11   (1<<1)    /* R/W */
#define UDR10   (1<<0)    /* R/W */


#define UCSR2A      0xD0 /* RXC2     |TXC2     |UDRE2    |FE2      |DOR2     |UPE2     |U2X2     |MPCM2     */
#define RXC2      (1<<7)    /* R/W */  /* Receive Complete    */               
#define TXC2      (1<<6)    /* R/W */  /* Transmit Complete   */               
#define UDRE2     (1<<5)    /* R/W */  /* Data Register Empty */               
#define FE2       (1<<4)    /* R/W */  /* Frame Error         */               
#define DOR2      (1<<3)    /* R/W */  /* Data Overrun        */               
#define UPE2      (1<<2)    /* R/W */  /* Parity Error        */               
#define U2X2      (1<<1)    /* R/W */  /* Double Transmission Speed */         
#define MPCM2     (1<<0)    /* R/W */  /* Multi-processor Communication Mode */

#define UCSR2B      0xD1 /* RXCIE2   |TXCIE2   |UDRIE2   |RXEN2    |TXEN2    |UCSZ22   |RXB82    |TXB82     */
#define RXCIE2    (1<<7)    /* R/W */  /* RX Complete Interrupt Enable */           
#define TXCIE2    (1<<6)    /* R/W */  /* TX Complete Interrupt Enable */           
#define UDRIE2    (1<<5)    /* R/W */  /* Data Register Empty Interrupt Enable */   
#define RXEN2     (1<<4)    /* R/W */  /* Receiver Enable */                        
#define TXEN2     (1<<3)    /* R/W */  /* Transmitter Enable */                     
#define UCSZ22    (1<<2)    /* R/W */  /* Character Size */                         
#define RXB82     (1<<1)    /* R/W */  /* Receive Data Bit 8 */                     
#define TXB82     (1<<0)    /* R/W */  /* Transmit Data Bit 8 */                    

#define UCSR2C      0xD2 /* UMSEL21  |UMSEL20  |UPM21    |UPM20    |USBS2    |UCSZ21   |UCSZ20   |UCPOL2    */
#define UMSEL21   (1<<7)    /* R/W */  /* Mode Select 01 */    
#define UMSEL20   (1<<6)    /* R/W */  /* Mode Select 00 */    
#define UPM21     (1<<5)    /* R/W */  /* Parity Mode 01 */    
#define UPM20     (1<<4)    /* R/W */  /* Parity Mode 00 */    
#define USBS2     (1<<3)    /* R/W */  /* Stop Bit Select */   
#define UCSZ21    (1<<2)    /* R/W */  /* Character Size 01 */ 
#define UCSZ20    (1<<1)    /* R/W */  /* Character Size 00 */ 
#define UCPOL2    (1<<0)    /* R/W */  /* Clock Polarity */    

#define UBRR2L      0xD4 /*  USART2 Baud Rate Register Low Byte                                             */
#define UBRR2L7   (1<<7)    /* R/W */
#define UBRR2L6   (1<<6)    /* R/W */
#define UBRR2L5   (1<<5)    /* R/W */
#define UBRR2L4   (1<<4)    /* R/W */
#define UBRR2L3   (1<<3)    /* R/W */
#define UBRR2L2   (1<<2)    /* R/W */
#define UBRR2L1   (1<<1)    /* R/W */
#define UBRR2L0   (1<<0)    /* R/W */

#define UBRR2H      0xD5 /* USART2 Baud Rate Register High Byte                                             */
#define UBRR2H3   (1<<3)    /* R/W */
#define UBRR2H2   (1<<2)    /* R/W */
#define UBRR2H1   (1<<1)    /* R/W */
#define UBRR2H0   (1<<0)    /* R/W */

#define UDR2        0xD6 /*  USART2 I/O Data Register                                                       */
#define UDR27   (1<<7)    /* R/W */
#define UDR26   (1<<6)    /* R/W */
#define UDR25   (1<<5)    /* R/W */
#define UDR24   (1<<4)    /* R/W */
#define UDR23   (1<<3)    /* R/W */
#define UDR22   (1<<2)    /* R/W */
#define UDR21   (1<<1)    /* R/W */
#define UDR20   (1<<0)    /* R/W */


/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTH) Registers                                                                     */
/*                                                                           */
/*****************************************************************************/
#define PINH       0x100 /* PINH7    |PINH6    |PINH5    |PINH4    |PINH3    |PINH2    |PINH1    |PINH0     */
#define PINH7     (1<<7)
#define PINH6     (1<<6)
#define PINH5     (1<<5)
#define PINH4     (1<<4)
#define PINH3     (1<<3)
#define PINH2     (1<<2)
#define PINH1     (1<<1)
#define PINH0     (1<<0)

#define DDRH       0x101 /* DDH7     |DDH6     |DDH5     |DDH4     |DDH3     |DDH2     |DDH1     |DDH0      */
#define DDH7      (1<<7)
#define DDH6      (1<<6)
#define DDH5      (1<<5)
#define DDH4      (1<<4)
#define DDH3      (1<<3)
#define DDH2      (1<<2)
#define DDH1      (1<<1)
#define DDH0      (1<<0)

#define PORTH      0x102 /* PORTH7   |PORTH6   |PORTH5   |PORTH4   |PORTH3   |PORTH2   |PORTH1   |PORTH0    */
#define PORTH7    (1<<7)
#define PORTH6    (1<<6)
#define PORTH5    (1<<5)
#define PORTH4    (1<<4)
#define PORTH3    (1<<3)
#define PORTH2    (1<<2)
#define PORTH1    (1<<1)
#define PORTH0    (1<<0)

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTJ) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINJ       0x103 /* PINJ7    |PINJ6    |PINJ5    |PINJ4    |PINJ3    |PINJ2    |PINJ1    |PINJ0     */
#define PINJ7     (1<<7)
#define PINJ6     (1<<6)
#define PINJ5     (1<<5)
#define PINJ4     (1<<4)
#define PINJ3     (1<<3)
#define PINJ2     (1<<2)
#define PINJ1     (1<<1)
#define PINJ0     (1<<0)

#define DDRJ       0x104 /* DDJ7     |DDJ6     |DDJ5     |DDJ4     |DDJ3     |DDJ2     |DDJ1     |DDJ0      */
#define DDJ7      (1<<7)
#define DDJ6      (1<<6)
#define DDJ5      (1<<5)
#define DDJ4      (1<<4)
#define DDJ3      (1<<3)
#define DDJ2      (1<<2)
#define DDJ1      (1<<1)
#define DDJ0      (1<<0)

#define PORTJ      0x105 /* PORTJ7   |PORTJ6   |PORTJ5   |PORTJ4   |PORTJ3   |PORTJ2   |PORTJ1   |PORTJ0    */
#define PORTJ7    (1<<7)
#define PORTJ6    (1<<6)
#define PORTJ5    (1<<5)
#define PORTJ4    (1<<4)
#define PORTJ3    (1<<3)
#define PORTJ2    (1<<2)
#define PORTJ1    (1<<1)
#define PORTJ0    (1<<0)

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTK) Registers                                                                     */
/*                                                                           */
/*****************************************************************************/
#define PINK       0x106 /* PINK7    |PINK6    |PINK5    |PINK4    |PINK3    |PINK2    |PINK1    |PINK0     */
#define PINK7     (1<<7)
#define PINK6     (1<<6)
#define PINK5     (1<<5)
#define PINK4     (1<<4)
#define PINK3     (1<<3)
#define PINK2     (1<<2)
#define PINK1     (1<<1)
#define PINK0     (1<<0)

#define DDRK       0x107 /* DDK7     |DDK6     |DDK5     |DDK4     |DDK3     |DDK2     |DDK1     |DDK0      */
#define DDK7      (1<<7)
#define DDK6      (1<<6)
#define DDK5      (1<<5)
#define DDK4      (1<<4)
#define DDK3      (1<<3)
#define DDK2      (1<<2)
#define DDK1      (1<<1)
#define DDK0      (1<<0)

#define PORTK      0x108 /* PORTK7   |PORTK6   |PORTK5   |PORTK4   |PORTK3   |PORTK2   |PORTK1   |PORTK0    */
#define PORTK7    (1<<7)
#define PORTK6    (1<<6)
#define PORTK5    (1<<5)
#define PORTK4    (1<<4)
#define PORTK3    (1<<3)
#define PORTK2    (1<<2)
#define PORTK1    (1<<1)
#define PORTK0    (1<<0)

/*****************************************************************************/
/*                                                                           */
/* GPIO (PORTL) Registers                                                    */
/*                                                                           */
/*****************************************************************************/
#define PINL       0x109 /* PINL7    |PINL6    |PINL5    |PINL4    |PINL3    |PINL2    |PINL1    |PINL0     */
#define PINL7     (1<<7)
#define PINL6     (1<<6)
#define PINL5     (1<<5)
#define PINL4     (1<<4)
#define PINL3     (1<<3)
#define PINL2     (1<<2)
#define PINL1     (1<<1)
#define PINL0     (1<<0)

#define DDRL       0x10A /* DDL7     |DDL6     |DDL5     |DDL4     |DDL3     |DDL2     |DDL1     |DDL0      */
#define DDL7      (1<<7)
#define DDL6      (1<<6)
#define DDL5      (1<<5)
#define DDL4      (1<<4)
#define DDL3      (1<<3)
#define DDL2      (1<<2)
#define DDL1      (1<<1)
#define DDL0      (1<<0)

#define PORTL      0x10B /* PORTL7   |PORTL6   |PORTL5   |PORTL4   |PORTL3   |PORTL2   |PORTL1   |PORTL0    */
#define PORTL7    (1<<7)
#define PORTL6    (1<<6)
#define PORTL5    (1<<5)
#define PORTL4    (1<<4)
#define PORTL3    (1<<3)
#define PORTL2    (1<<2)
#define PORTL1    (1<<1)
#define PORTL0    (1<<0)

/*****************************************************************************/
/*                                                                           */
/* Timer/Counter5  Registers                                                 */
/*                                                                           */
/*****************************************************************************/
#define TCCR5A     0x120 /* COM5A1   |COM5A0   |COM5B1   |COM5B0   |COM5C1   |COM5C0   |WGM51    |WGM50     */
#define COM5A1    (1<<7)
#define COM5A0    (1<<6)
#define COM5B1    (1<<5)
#define COM5B0    (1<<4)
#define COM5C1    (1<<3)
#define COM5C0    (1<<2)
#define WGM51     (1<<1)
#define WGM50     (1<<0)

#define TCCR5B     0x121 /* ICNC5    |ICES5    |-        |WGM53    |WGM52    |CS52     |CS51     |CS50      */
#define ICNC5     (1<<7)
#define ICES5     (1<<6)
#define WGM53     (1<<4)
#define WGM52     (1<<3)
#define CS52      (1<<2)
#define CS51      (1<<1)
#define CS50      (1<<0)

#define TCCR5C     0x122 /* FOC5A    |FOC5B    |FOC5C    |-        |-        |-        |-        |-         */
#define FOC5A     (1<<7)
#define FOC5B     (1<<6)
#define FOC5C     (1<<5)
#define TCNT5L     0x124 /* Timer/Counter5 - Counter Register Low Byte                                      */
#define TCNT5H     0x125 /* Timer/Counter5 - Counter Register High Byte                                     */
#define ICR5L      0x126 /* Timer/Counter5 - Input Capture Register Low Byte                                */
#define ICR5H      0x127 /* Timer/Counter5 - Input Capture Register High Byte                               */
#define OCR5AL     0x128 /* Timer/Counter5 - Output Compare Register A Low Byte                             */
#define OCR5AH     0x129 /* Timer/Counter5 - Output Compare Register A High Byte                            */
#define OCR5BL     0x12A /* Timer/Counter5 - Output Compare Register B Low Byte                             */
#define OCR5BH     0x12B /* Timer/Counter5 - Output Compare Register B High Byte                            */
#define OCR5CL     0x12C /* Timer/Counter5 -Output Compare Register C Low Byte                              */
#define OCR5CH     0x12D /* Timer/Counter5 -Output Compare Register C High Byte                             */

/*****************************************************************************/
/*                                                                           */
/* USART3 Registers                                                          */
/*                                                                           */
/*****************************************************************************/
#define UCSR3A     0x130 /* RXC3     |TXC3     |UDRE3    |FE3      |DOR3     |UPE3     |U2X3     |MPCM3     */
#define RXC3      (1<<7) /* Receive Complete    */               
#define TXC3      (1<<6) /* Transmit Complete   */               
#define UDRE3     (1<<5) /* Data Register Empty */               
#define FE3       (1<<4) /* Frame Error         */               
#define DOR3      (1<<3) /* Data Overrun        */               
#define UPE3      (1<<2) /* Parity Error        */               
#define U2X3      (1<<1) /* Double Transmission Speed */         
#define MPCM3     (1<<0) /* Multi-processor Communication Mode */

#define UCSR3B     0x131 /* RXCIE3   |TXCIE3   |UDRIE3   |RXEN3    |TXEN3    |UCSZ32   |RXB83    |TXB83     */
#define RXCIE3    (1<<7) /* RX Complete Interrupt Enable */           
#define TXCIE3    (1<<6) /* TX Complete Interrupt Enable */           
#define UDRIE3    (1<<5) /* Data Register Empty Interrupt Enable */   
#define RXEN3     (1<<4) /* Receiver Enable */                        
#define TXEN3     (1<<3) /* Transmitter Enable */                     
#define UCSZ32    (1<<2) /* Character Size */                         
#define RXB83     (1<<1) /* Receive Data Bit 8 */                     
#define TXB83     (1<<0) /* Transmit Data Bit 8 */                    

#define UCSR3C     0x132 /* UMSEL31  |UMSEL30  |UPM31    |UPM30    |USBS3    |UCSZ31   |UCSZ30   |UCPOL3    */
#define UMSEL31   (1<<7) /* Mode Select 01 */    
#define UMSEL30   (1<<6) /* Mode Select 00 */    
#define UPM31     (1<<5) /* Parity Mode 01 */    
#define UPM30     (1<<4) /* Parity Mode 00 */    
#define USBS3     (1<<3) /* Stop Bit Select */   
#define UCSZ31    (1<<2) /* Character Size 01 */ 
#define UCSZ30    (1<<1) /* Character Size 00 */ 
#define UCPOL3    (1<<0) /* Clock Polarity */    

#define UBRR3L     0x134 /*  USART3 Baud Rate Register Low Byte                                             */
#define UBRR37   (1<<7)    /* R/W */
#define UBRR36   (1<<6)    /* R/W */
#define UBRR35   (1<<5)    /* R/W */
#define UBRR34   (1<<4)    /* R/W */
#define UBRR33   (1<<3)    /* R/W */
#define UBRR32   (1<<2)    /* R/W */
#define UBRR31   (1<<1)    /* R/W */
#define UBRR30   (1<<0)    /* R/W */

#define UBRR3H     0x135 /* USART3 Baud Rate Register High Byte                                             */
#define UBRR3H3   (1<<3)    /* R/W */
#define UBRR3H2   (1<<2)    /* R/W */
#define UBRR3H1   (1<<1)    /* R/W */
#define UBRR3H0   (1<<0)    /* R/W */

#define UDR3       0x136 /*  USART3 I/O Data Register                                                       */
#define UDR37   (1<<7)    /* R/W */
#define UDR36   (1<<6)    /* R/W */
#define UDR35   (1<<5)    /* R/W */
#define UDR34   (1<<4)    /* R/W */
#define UDR33   (1<<3)    /* R/W */
#define UDR32   (1<<2)    /* R/W */
#define UDR31   (1<<1)    /* R/W */
#define UDR30   (1<<0)    /* R/W */

#endif /* __atmega2560_H__ */
