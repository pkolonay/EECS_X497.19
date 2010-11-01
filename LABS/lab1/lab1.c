/* LAB 1 - Writing Portable Device Drivers */
/* poor example of portability              */
/* fine for tool demonstration              */
/* Aaron Baranoff                          */


void delay(unsigned int val)
{
	volatile unsigned int temp;
	unsigned int temp2;

	for(temp = 0; temp < val; temp++) 
		for (temp2 = 0; temp2 < val; temp2 ++) ;
}

int main(void)
{
	*((volatile unsigned char *)0x24) = 0xff;
	while(1) {
	 	*((volatile unsigned char *)0x25) = 0;
	 	delay(200);
	 	*((volatile unsigned char *)0x25) = 0xff;
	 	delay(200);
	}

	return(0);
}

