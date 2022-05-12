/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#ifndef CA_H_
#define CA_H_
#include"state.h"
STATE_DEFINE(CA_Waiting);
STATE_DEFINE(CA_Driving);
int us_getdistance(int s,int b,int count);
 enum
{
	CA_WAITING,
	CA_DRIVING
}CA_STATE_ID;

#endif /* CA_H_ */
