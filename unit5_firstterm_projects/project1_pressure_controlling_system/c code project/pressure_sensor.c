#include "pressure_sensor.h"
int pval=0;
void pressure_sensor_init()
{
}
STATE_DEFINE(PS_reading)
{
PS_state_id=PS_reading;
pval=getPressureVal();
set_pressure(pval);
PS_state=STATE(PS_reading);
}
/*
STATE_DEFINE(PS_waiting)
{
PS_state_id=PS_waiting;
Delay(100000);
PS_state=STATE(PS_reading);
}

*/
