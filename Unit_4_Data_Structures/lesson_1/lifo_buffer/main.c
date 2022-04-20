/*
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include<stdio.h>
#include"lifo.h""
unsigned int buffer1[5];
void main()
{
unsigned int i,temp;
LIFO_buf_t uart_buf;
LIFO_init(&uart_buf,buffer1,7);
for(i=0;i<5;i++)
{
	if(LIFO_add_item(&uart_buf,i)==LIFO_NO_ERROR)
		printf("uart lifo add : %d\n",i);
}
for(i=0;i<5;i++)
{
	if(LIFO_get_item(&uart_buf,&temp)==LIFO_NO_ERROR)
		printf("uart lifo get : %d\n",temp);
}

}

