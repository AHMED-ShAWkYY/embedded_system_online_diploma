/*
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#include"fifo.h"
void main()
{
	element_type temp;
	unsigned int i ;
	FIFO_buf_t uart_buf;
	FIFO_init(&uart_buf,buffer1,5);
	for(i=0;i<7;i++)
	{
		printf("fifo enqueue\n");
		if(FIFO_enqueue(&uart_buf,i)==FIFO_no_error)
		{
			printf("fifo done\n");
		}
		else
		{
			printf("fifo failed\n");
		}
	}
	FIFO_Print(&uart_buf);
	if(FIFO_dequeue(&uart_buf,&temp)==FIFO_no_error);
	printf("dequeue %d is done\n",temp);
	if(FIFO_dequeue(&uart_buf,&temp)==FIFO_no_error);
	printf("dequeue %d is done\n",temp);
	FIFO_Print(&uart_buf);
	for(i=0;i<2;i++)
	{
		printf("fifo enqueue\n");
		if(FIFO_enqueue(&uart_buf,i+5)==FIFO_no_error)
		{
			printf("fifo %d is done\n",i+5);
		}
		else
		{
			printf("fifo failed\n");
		}
	}
	FIFO_Print(&uart_buf);

/*	printf("array values\n");
	for(i=0;i<5;i++)
		printf("%d\n",buffer1[i]);
	printf("the frist element %d\n",buffer1[0]);
	printf("the second element %d\n",buffer1[1]);*/
}
