/*
 * state.h
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#ifndef STATE_H_
#define STATE_H_
#define STATE_DEFINE(_define) void st_##_define()
#define STATE(_define) st_##_define
//Apis
void set_pressure(int pval);
void high_pressure_detected();
extern void Set_Alarm_actuator(int i);

#endif /* STATE_H_ */
