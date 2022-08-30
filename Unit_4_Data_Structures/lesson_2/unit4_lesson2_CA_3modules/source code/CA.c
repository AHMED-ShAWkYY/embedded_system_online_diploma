/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include"CA.h"
#include "stdlib.h"
void (*CA_State)();
int CA_speed=0;
extern int CA_distance;
int CA_threeshold=50;

STATE_DEFINE(CA_Waiting)
{
	CA_STATE_ID=CA_WAITING;
	//init speed
	CA_speed=0;
	//send speed to DC_motor
	DC_set_speed(CA_speed);
	printf("CA_WAITING: distance=%d speed=%d\n",CA_distance,CA_speed);
}
STATE_DEFINE(CA_Driving)
{
	CA_STATE_ID=CA_DRIVING;
	//init speed
	CA_speed=30;
	//send speed to DC_motor
	DC_set_speed(CA_speed);
	printf("CA_Driving: distance=%d speed=%d\n",CA_distance,CA_speed);

}
void US_set_distance(int d)
{
	CA_distance=d;
	(CA_distance<=50)?(CA_State=STATE(CA_Waiting)):(CA_State=STATE(CA_Driving));

}
void CA_init()
{
	printf("CA init\n");
}
