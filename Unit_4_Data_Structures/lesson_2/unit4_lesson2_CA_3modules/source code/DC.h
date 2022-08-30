

#ifndef DC_H_
#define DC_H_
#include"state.h"
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);
extern void (*DC_State)();
void DC_init();
enum
{
	DC_idle,
	DC_busy
}DC_STATE_ID;

#endif /* DC_H_ */
