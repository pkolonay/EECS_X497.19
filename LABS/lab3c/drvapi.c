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

DRVUSART serial_port;
void serial_init(UINT16 baud, UINT8 stop_bits, UINT8 data_bits, UINT8 parity) {

    serial_port.baseaddr = USART0_BASEADDR;
    drv_usart_init(serial_port, baud, stop_bits, data_bits, parity);

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
