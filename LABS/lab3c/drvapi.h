#include "drvcore.h"

#define SDK600

#ifdef SDK600
#define NUMBEROFLEDS 8

#define LED_OFF 1
#define LED_ON  0

#endif

void gpio_init(PDRVCTRL , UINT8 );

UINT8 gpio_read_pin(PDRVCTRL , UINT8, UINT8 );

void gpio_write_pin(PDRVCTRL , UINT8, UINT8, UINT8 );

void board_led_on(UINT8);

void board_led_off(UINT8);


void drvinit();


void delay_mSec();

