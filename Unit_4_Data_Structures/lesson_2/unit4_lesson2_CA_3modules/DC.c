/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */
#include"DC.h"
#include "stdlib.h"
void (*DC_State)();
int DC_speed=0;

STATE_DEFINE(DC_idle)
{
	DC_STATE_ID=DC_idle;

	printf("DC idle state =%d\n",DC_speed);
}
STATE_DEFINE(DC_busy)
{
	DC_STATE_ID=DC_busy;

	DC_State=STATE(DC_idle);

printf("DC busy state =%d\n",DC_speed);
}
void DC_set_speed(int s)
{
DC_speed=s;
DC_State=STATE(DC_busy);
printf("CA...........speed.........DC\n");
}
void DC_init()
{
	printf("DC INIT\n");
}
