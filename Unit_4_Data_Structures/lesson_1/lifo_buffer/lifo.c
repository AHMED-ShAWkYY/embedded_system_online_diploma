/*
 * lifo.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include"lifo.h"
LIFO_STATUS LIFO_add_item(LIFO_buf_t*LIFO_P,unsigned int item)
{
	//check if buf is valid
	if (!LIFO_P->LIFO_base||!LIFO_P->LIFO_head)
		return LIFO_NULL;

	//check if buf is full
	if(LIFO_P->LIFO_count==LIFO_P->LIFO_length)
		return LIFO_FILL;
	*(LIFO_P->LIFO_head)=item;
	LIFO_P->LIFO_head++;
	LIFO_P->LIFO_count++;
	return LIFO_NO_ERROR;
}
LIFO_STATUS LIFO_get_item(LIFO_buf_t*LIFO_P,unsigned int*item)
{
	//check if buf is valid
	if (!LIFO_P->LIFO_base||!LIFO_P->LIFO_head)
		return LIFO_NULL;
	//check if buf is empty
	if(LIFO_P->LIFO_count==0)
		return LIFO_EMPTY ;
	LIFO_P->LIFO_head--;
	*item=*(LIFO_P->LIFO_head);
	LIFO_P->LIFO_count--;
	return LIFO_NO_ERROR;

}
LIFO_STATUS LIFO_init(LIFO_buf_t*LIFO_P,unsigned int*item,unsigned int length)
{
	//check if buf is valid
	if(item==NULL)
		return LIFO_NULL;
	//initalize the pointers with buffer
	LIFO_P->LIFO_base=item;
	LIFO_P->LIFO_head=item;
	LIFO_P->LIFO_length=length;
	LIFO_P->LIFO_count=0;
	return LIFO_NO_ERROR;
}
