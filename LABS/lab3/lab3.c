#include "..\inc\atmega2560.h"

#define UINT16 unsigned int
#define UINT8 unsigned char

/* delay in milliseconds */
static const UINT16 DELAY = 1000;

/* set to the frequency of the cpu (khz)*/
static const UINT16 CPU_FREQ = 1000;


UINT16 read_timer() {

    UINT16 timer_value = HWREG(TCNT1L);
	timer_value |= HWREG(TCNT1H);

    return (timer_value);
}

void write_timer(int value) {
	HWREG(TCNT1H) = ((value & 0xF0) >> 8);
    HWREG(TCNT1L) = (value  & 0x0F);

}

void reset_timer() {
	HWREG(TCNT1H) = 0;
    HWREG(TCNT1L) = 0;
}

void delay(int milliSeconds) {

	volatile UINT16 timer_value = 0;
	/* 1/20th of a second for 1MHz clock CPU clock */
	volatile UINT16 compare = 49999;

  
	/* normall mode */
	HWREG(TCCR1A) &= (UINT8) ~(WGM11 | WGM10);
	HWREG(TCCR1B) &= (UINT8) ~(WGM13 | WGM12);
	/* no prescale */
	HWREG(TCCR1B) |= CS10;

	/* reset the counter */
	HWREG(TCNT1H) = 0;
    HWREG(TCNT1L) = 0;


	while( 1  ) {
	    timer_value = HWREG(TCNT1L);
		timer_value |= (HWREG(TCNT1H) << 8);
		if (timer_value >= compare) return;
    }

}
int main()
{
    int i;
	unsigned char j;
	int delay_multiplier = 1;
    HWREG(DDRB) = 0xff; 
	HWREG(DDRD) = 0x00; 
	    

	while(1) {
	                    
        for( j = 0;j<8;j++) {

				
            HWREG(PORTB) = (UINT8)~(1<<j);
	    	/* the delay provides 1/20th of a second delay */
		    /* calling it 10 times should result in .5 second delay */
    		for(i=0;i<delay_multiplier;i++) delay(60);
        
	        HWREG(PORTB) = 0xff;
		    for(i=0;i<delay_multiplier;i++) delay(60);
		    if ((UINT8)~HWREG(PIND) & (1<<j)) break;
		}
    }
}
