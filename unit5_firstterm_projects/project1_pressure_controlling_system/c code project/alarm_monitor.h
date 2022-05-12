

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include"state.h"
#include "driver.h"
STATE_DEFINE(AM_alarmoff);
STATE_DEFINE(AM_alarmon);
STATE_DEFINE(AM_waiting);
void (* AM_state) ();
enum
{
	AM_alarmoff,
	AM_alarmon,
	AM_waiting
}AM_state_id;


#endif /* ALARM_MONITOR_H_ */
