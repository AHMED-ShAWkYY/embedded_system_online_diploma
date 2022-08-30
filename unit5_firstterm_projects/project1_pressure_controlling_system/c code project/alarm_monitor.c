#include"alarm_monitor.h"
STATE_DEFINE(AM_alarmoff)
{
	AM_state_id=AM_alarmoff;

	Set_Alarm_actuator(0);

	
}
STATE_DEFINE(AM_alarmon)
{
	AM_state_id=AM_alarmon;

	Set_Alarm_actuator(1);

	Delay(600000);

	Set_Alarm_actuator(0);

	AM_state=STATE(AM_alarmoff);

}
/*STATE_DEFINE(AM_waiting)
{
	AM_state_id=AM_waiting;

	Delay(60000);

	AM_state=STATE(AM_alarmoff);

}*/
void high_pressure_detected()
{
	AM_state=STATE(AM_alarmon);
}
