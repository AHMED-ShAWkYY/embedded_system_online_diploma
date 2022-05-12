

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include"state.h"
#include "driver.h"
void pressure_sensor_init();
STATE_DEFINE(PS_reading);
STATE_DEFINE(PS_waiting);
void (* PS_state) ();
enum
{
	PS_reading,
	PS_waiting
}PS_state_id;
#endif /* PRESSURE_SENSOR_H_ */
