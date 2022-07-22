/*
 * GPIO_project1.c
 *
 * Created: 7/22/2022 11:03:24 AM
 * Author : PC
 */ 
#define F_CPU 8000000UL
#include "memmap.h"
#include "utils.h"
#include "util/delay.h"
int main(void)
{
int i=0,x=10;
DDRA=255;
clearbit(DDRB,0);
setbit(PORTB,0);
    while (1) 
    {
		if((getbit(PINB,0)==0)&&(x==10))
		{
		setbit(PORTA,i);
		i++;
		if(i==8)
		{
			i--;
			x=0;
		}
		}
		else if((getbit(PINB,0)==0)&&(x==0))
		{
		clearbit(PORTA,i);
		i--;
		if(i==-1)
		{
			i++;
			x=10;
		}
		}
		_delay_ms(1000);		
		}
		}	
		