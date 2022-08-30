#include<stdio.h>
char str_buffer[100]="learn-in-depth<ahmed-shawki>";
void main()
{
	uart_send_string(str_buffer);
}