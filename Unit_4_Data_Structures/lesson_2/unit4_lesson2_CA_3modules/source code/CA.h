/*
 * CA.h
 *
 *  Created on: ??�/??�/????
 *      Author: ���� ���������
 */

#ifndef CA_H_
#define CA_H_
#include"state.h"
STATE_DEFINE(CA_Waiting);
STATE_DEFINE(CA_Driving);
void CA_init();
extern void (*CA_State)();
enum
{
	CA_WAITING,
	CA_DRIVING
}CA_STATE_ID;

#endif /* CA_H_ */
