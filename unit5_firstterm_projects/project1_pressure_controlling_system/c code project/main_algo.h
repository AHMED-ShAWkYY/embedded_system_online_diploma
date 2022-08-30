
#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_
#include"state.h"
#include "driver.h"
STATE_DEFINE(MA_high_pressure);
void (* MA_state) ();
enum
{
	MA_high_pressure,
}MA_state_id;


#endif /* MAIN_ALGO_H_ */
