/*
 * fifo.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#include"fifo.h"
#include<stdio.h>
#include<stdint.h>
FIFO_status FIFO_init(FIFO_buf_t*FIFO_P,element_type *P_buf,unsigned int length)
{
	//check if buffer is valid
	if(P_buf== NULL)
		return FIFO_null;
	FIFO_P->FIFO_base=P_buf;
	FIFO_P->FIFO_head=P_buf;
	FIFO_P->FIFO_tail=P_buf;
	FIFO_P->FIFO_length=length;
	FIFO_P->FIFO_count=0;
	return FIFO_no_error;
}
FIFO_status FIFO_enqueue(FIFO_buf_t*FIFO_P,element_type item)
{
	//check buf is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;
	//check buf is full
	if(FIFO_is_full(FIFO_P)==FIFO_full)
		return FIFO_full;
	if(FIFO_P->FIFO_head==(FIFO_P->FIFO_base+FIFO_P->FIFO_length*sizeof(element_type)))
		FIFO_P->FIFO_head=FIFO_P->FIFO_base;
	*(FIFO_P->FIFO_head)=item;
	FIFO_P->FIFO_head++;
		FIFO_P->FIFO_count++;
	return FIFO_no_error;
}
FIFO_status FIFO_dequeue(FIFO_buf_t*FIFO_P,element_type *item)
{
	//check fifo is empty
	if(FIFO_P->FIFO_count==0)
		return FIFO_empty;
	*item=*(FIFO_P->FIFO_tail);
	FIFO_P->FIFO_count--;
	if(FIFO_P->FIFO_tail==(FIFO_P->FIFO_base+FIFO_P->FIFO_length*sizeof(element_type)))
		FIFO_P->FIFO_tail=FIFO_P->FIFO_base;
	else
		FIFO_P->FIFO_tail++;
	return FIFO_no_error;
}
FIFO_status FIFO_is_full(FIFO_buf_t*FIFO_P)
{
	//check buf is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;
	if(FIFO_P->FIFO_count==FIFO_P->FIFO_length)
		return FIFO_full;
	else
		return FIFO_no_error;
}
void FIFO_Print(FIFO_buf_t*FIFO_P)
{

/*	unsigned int i;
	element_type*temp;
	if(FIFO_P->FIFO_count==0)
		printf("fifo is empty");
	else
	{
		temp=FIFO_P->FIFO_tail;
		printf("******fifo print*****\n");
		for(i=0;i<FIFO_P->FIFO_count;i++,temp++)
		printf("%d\n",*temp);
		printf("********************\n");
	}
}
	*/
	unsigned int i,j;
		element_type*temp;
		if(FIFO_P->FIFO_count==0)
			printf("fifo is empty");
		else
		{
			printf("******fifo print*****\n");
			for(i=0,j=0;i<FIFO_P->FIFO_count;i++)
			{
			if((FIFO_P->FIFO_tail+i)==(FIFO_P->FIFO_base+FIFO_P->FIFO_length*sizeof(element_type)))
			{
				FIFO_P->FIFO_tail=FIFO_P->FIFO_base;
				j=i;
			}
				temp=FIFO_P->FIFO_tail+i-j;
				printf("%d\n",*temp);
			}
			printf("********************\n");
}
}

