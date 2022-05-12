/*
 * CA.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include"CA.h"
#include "stdlib.h"
void (*P_State)();
int CA_speed=0;
int CA_distance=0;
int CA_threeshold=50;

STATE_DEFINE(CA_Waiting)
{
	CA_STATE_ID=CA_WAITING;
	//init speed
	CA_speed=0;
	//get US distance
	CA_distance=us_getdistance(45,55,1);
	(CA_distance<=50)?(P_State=STATE(CA_Waiting)):(P_State=STATE(CA_Driving));
	printf("CA_WAITING: distance=%d speed=%d\n",CA_distance,CA_speed);
}
STATE_DEFINE(CA_Driving)
{
	CA_STATE_ID=CA_DRIVING;
	//init speed
	CA_speed=30;
	//get US distance
	CA_distance=us_getdistance(45,55,1);
	(CA_distance<=CA_threeshold) ? (P_State=STATE(CA_Waiting)):(P_State=STATE(CA_Driving));
	printf("CA_Driving: distance=%d speed=%d\n",CA_distance,CA_speed);

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
