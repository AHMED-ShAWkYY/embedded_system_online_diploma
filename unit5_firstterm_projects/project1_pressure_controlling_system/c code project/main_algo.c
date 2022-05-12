
#include "main_algo.h"
int pressurevalue=0,threshold=20;
STATE_DEFINE(MA_high_pressure)
{
	MA_state_id=MA_high_pressure;
	if(pressurevalue<=threshold)
	{
		MA_state=STATE(MA_high_pressure);
	}
	else
	{
		high_pressure_detected();
		MA_state=STATE(MA_high_pressure);
	}
}
void set_pressure(int pval)
{
	pressurevalue=pval;
	//MA_state=STATE(MA_high_pressure);
}
