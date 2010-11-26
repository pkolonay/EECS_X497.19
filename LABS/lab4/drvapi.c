/* P.E. Kolonay */
#include "drvapi.h"

void drvinit() {
;
}

/* initialize gpio for specific port */
void gpio_init(PDRVCTRL ctrl, UINT8 portid) {
    DRVGPIO gpio = ctrl->gpio;
	gpio.baseaddr = portid;

}

/* read a pin from port spcified in gpio */
UINT8 gpio_read_pin(PDRVCTRL gpio, UINT8 portid, UINT8 pinid) {
    return(read_pin(portid,pinid));
}

void gpio_write_pin(PDRVCTRL gpio, UINT8 portid, UINT8 pinid, UINT8 value) {
    write_pin(portid,pinid,value);
}
void gpio_pin_on()
{
}

/* platform */
void board_led_on(UINT8 pinid)
{
    write_pin(PORTB,pinid,LED_ON);

}

void board_led_off(UINT8 pinid)
{
    write_pin(PORTB,pinid,LED_OFF);

}


void serial_write() {


}


void serial_read() {

}

void init_timer() {

    timer_init(100);

}
/*
COnfigure a period task. This would set up a timer to 
trigger an interrupt and call function.

void configurePeriodicTask(UINT8 msec,function)
{


}
*/
