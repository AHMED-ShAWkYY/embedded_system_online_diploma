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
	int i;
	clearbit(DDRD,0);
	setbit(DDRD,4);
    while (1) 
    {
					if(getbit(PIND,0)==1)
					{
					setbit(PORTD,4);
					_delay_ms(1000);
					clearbit(PORTD,4);
					_delay_ms(1000);
	}
	}			
	}