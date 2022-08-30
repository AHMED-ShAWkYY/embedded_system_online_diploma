

#ifndef US_H_
#define US_H_
#include"state.h"
STATE_DEFINE(US_busy);
void US_init();
int us_getdistance(int s,int b,int count);
extern void (*US_State)();
enum
{
	US_busy
}US_STATE_ID;

#endif /* US_H_ */
