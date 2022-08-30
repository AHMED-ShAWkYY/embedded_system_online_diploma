/*
 * lifo.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#ifndef LIFO_H_
#define LIFO_H_
#include<stdlib.h>
typedef struct
{
	unsigned int *LIFO_base;
	unsigned int *LIFO_head;
	unsigned int LIFO_count;
	unsigned int LIFO_length;
}LIFO_buf_t;
typedef enum
{
LIFO_NULL,
LIFO_NO_ERROR,
LIFO_FILL,
LIFO_EMPTY
}LIFO_STATUS;
//API
LIFO_STATUS LIFO_add_item(LIFO_buf_t*LIFO_P,unsigned int item);
LIFO_STATUS LIFO_get_item(LIFO_buf_t*LIFO_P,unsigned int*item);
LIFO_STATUS LIFO_init(LIFO_buf_t*LIFO_P,unsigned int*item,unsigned int length);

#endif /* LIFO_H_ */
