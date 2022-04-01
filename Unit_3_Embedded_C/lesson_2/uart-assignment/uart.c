#include"uart.h"
#define UART_DR *((volatile unsigned int *)((unsigned int *)0x101f1000))
void uart_send_string(char * p_tx_string)
{
while(*p_tx_string!='\0')
{
	UART_DR=(unsigned int)*p_tx_string;
	p_tx_string++;
}	
}
