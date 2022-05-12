#include "alarm_monitor.h"
#include "pressure_sensor.h"
#include "main_algo.h"
#include "driver.h"
void setup()
{
	GPIO_INITIALIZATION();
	PS_state=STATE(PS_reading);
	MA_state=STATE(MA_high_pressure);
	AM_state=STATE(AM_alarmoff);
}

void main()
{
setup();
while(1)
{
	PS_state();
	MA_state();
	AM_state();
}
}


