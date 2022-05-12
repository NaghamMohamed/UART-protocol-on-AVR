#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include"ADC/ADC.h"
unsigned char mailbox;
unsigned char flag;
//#include "URT driver/USART.h"
#define BAUD 4800
int main(void)
{
	UCSRC|=(1<<7);	//to enable writing to UCSRC register
	UCSRB|=(1<<4);	//enable UART receiver
	UCSRC|=(3<<1);	//character size = 8 bits
	UCSRB|=(1<<7);	//enable receive interrupt flag
	UBRRL=(F_CPU/((long)16*BAUD))-1;		//4800 byte for 1 MHZ
	
	DDRA=0xff;
	sei();
	DDRB=0xff;
    while(1)
    {    
         /*if(flag==1)
		 {
			 flag=0;
			 PORTA=mailbox;			 			 
		 }
		 PORTB=0xff;*/
		 while((UCSRA&(1<<7))==0);
		 PORTC=UDR	;
    
}
}

/*ISR(USART0_RX_vec)
{
	mailbox=UDR;
	flag=1;
}*/