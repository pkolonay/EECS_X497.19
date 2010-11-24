#ifndef __DRVREG_H__
#define __DRVREG_H__



#define PIN0           0

/**
 * STK600 Board specific 
 */
#define LED0           0


#define DRV_PORTB      0x23
#define DRV_PORTD      0x29

#define DRV_GPIO_PIN_OFFSET   0
#define DRV_GPIO_DIR_OFFSET   1
#define DRV_GPIO_PORT_OFFSET  2



#define USART0_BASEADDR    0xC0
#define USART1_BASEADDR    0xC8
#define USART2_BASEADDR    0xD0
#define USART3_BASEADDR    0x130

#define USART_UCSRA_OFFSET 0
#define USART_RX_COMP 1<<7
#define USART_TX_COMP 1<<6
#define USART_DATA_REG_EMPTY 1<<5

#define USART_DATA_REG_EMPTY_POS 5

#define USART_UCSRB_OFFSET 1
#define USART_RX_COMP_IE   1<<7
#define USART_TX_COMP_IE   1<<6
#define USART_REG_EMPTY_IE   1<<5
#define USART_RX_EN   1<<4
#define USART_TX_EN   1<<3


#define USART_UCSRC_OFFSET 2
#define USART_NO_PARITY    0
#define USART_1_STOP_BITS  0
#define USART_2_STOP_BITS  1<<1
#define USART_8_DATA_BITS  3<<1

#define USART_UBRR_OFFSET USART_UBRRL_OFFSET
#define USART_UBRRL_OFFSET 4
#define USART_UBRRH_OFFSET 5


#define USART_UDR_OFFSET   6


#define EEPROM_BASE               EECR
#define EEPROM_CTRL_OFFSET        0
#define EEPROM_MODE_ERASE_WRITE   0<<4
#define EEPROM_MODE_ERASE_ONLY    1<<4
#define EEPROM_MODE_WRITE_ONLY    2<<4
#define EEPROM_RDY_INT_EN         1<<3
#define EEPROM_MSTR_PRG_EN        1<<2 
#define EEPROM_PRG_EN             1<<1 
#define EEPROM_READ_EN            1<<0


#define EEPROM_DATA_OFFSET        1

#define EEPROM_ADDR_LO_OFFSET     2
#define EEPROM_ADDR_HI_OFFSET     3
#define EEPROM_ADDR_OFFSET        EEPROM_ADDR_LO_OFFSET









/**
 *(0xC6) UDR0 USART0 I/O Data Register 222
 *(0xC5) UBRR0H - - - - USART0 Baud Rate Register High Byte 227
 *(0xC4) UBRR0L USART0 Baud Rate Register Low Byte 227
 *(0xC3) Reserved - - - - - - - -
 *(0xC2) UCSR0C UMSEL01 UMSEL00 UPM01 UPM00 USBS0 UCSZ01 UCSZ00 UCPOL0 239
 *(0xC1) UCSR0B RXCIE0 TXCIE0 UDRIE0 RXEN0 TXEN0 UCSZ02 RXB80 TXB80 238
 *(0xC0) UCSR0A RXC0 TXC0 UDRE0 FE0 DOR0 UPE0 U2X0 MPCM0 238
 */

#endif
