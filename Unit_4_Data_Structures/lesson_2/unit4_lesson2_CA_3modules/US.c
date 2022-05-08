/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include"US.h"
#include "stdlib.h"
void (*US_State)();
int CA_distance=0;
void US_init()
{
	printf("us init\n");
}
STATE_DEFINE(US_busy)
{
	US_STATE_ID=US_busy;
	//get US distance
	CA_distance=us_getdistance(45,55,1);
	US_set_distance(CA_distance);
	printf("US........... distance=%d...........CA\n",CA_distance);
	US_State=STATE(US_busy);
}

int us_getdistance(int s,int b,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		int rand_num=(rand() % (b-s+1)) + s;
		return rand_num;
	}
}
