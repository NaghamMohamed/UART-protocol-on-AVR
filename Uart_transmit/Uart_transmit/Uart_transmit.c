//#define F_CPU 1000000UL
#include <avr/io.h>
#include"ADC/ADC.h"

int main(void)
{
	ADC_enable();
	UCSRC|=(1<<7);	//to enable writing to UCSRC register
	UCSRB|=(1<<3);	//enable UART transmitter
	UCSRC|=(3<<1);	//character size = 8 bits
	UBRRL=12;		//4800 byte for 1 MHZ
	DDRC=0xff;
	DDRB=0xff;
	unsigned int data;
    while(1)
    {
		 data=Convert_single(0);
         while( ( UCSRA & (1<<5) )==0 );             //polling data register empty flag in(UCSRA) before writing to UDR register
		 UDR=data;
		 PORTC=data;
    }
}