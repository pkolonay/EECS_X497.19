#include "drvapi.h"



int main() {
    UINT8 pinvalue;

    DRVCTRL example;

    drvinit(example);

	pinvalue = gpio_read_pin(&example,PORTD, 1);

	init_gpio(DRV_PORTB);
	init_gpio(DRV_PORTD);

    /* I would really like to be able to implement a 
	   function where I could just pass a pointer to a
	   function that would be called when the timer
	   overflowed, like the one below.
    */
    /* schedulePeriodicTask(timePeriod,&task); */
    init_timer();

    init_usart0();

    init_eeprom();

	process();
    
    while (1) {
	;
    }


}
