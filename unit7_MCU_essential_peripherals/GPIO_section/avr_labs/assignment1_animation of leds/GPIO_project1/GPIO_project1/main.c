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
DDRA=255;
    while (1) 
    {
		for(i=0;i<8;i++)
		{
			setbit(PORTA,i);
			_delay_ms(500);
		}
		for(i=7;i>=0;i--)
		{
			clearbit(PORTA,i);
			_delay_ms(500);
		}

    }
}

