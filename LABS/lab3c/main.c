#include "drvapi.h"



int main() {
    UINT8 pinvalue;
	UINT8 i;

    DRVCTRL example;

    drvinit(example);

	pinvalue = gpio_read_pin(&example,(UINT8)PORTD, (UINT8)0x1);


    while (1) {
        for ( i = 0; i < NUMBEROFLEDS; i++) {

	        board_led_on(i);

		    delay_mSec();



	        board_led_off(i);

		    delay_mSec();
        }
    }


}
