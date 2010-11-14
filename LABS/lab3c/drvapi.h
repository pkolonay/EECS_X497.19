#include "drvcore.h"

#define SDK600

#ifdef SDK600
#define NUMBEROFLEDS 8
#endif

void gpio_init(PDRVCTRL , UINT8 );

UINT8 gpio_read_pin(PDRVCTRL , UINT8, UINT8 );

void gpio_write_pin(PDRVCTRL , UINT8, UINT8, UINT8 );

void led_on();

void led_off();


void drvinit();


void delay_mSec();

