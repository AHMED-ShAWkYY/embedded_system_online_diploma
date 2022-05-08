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
void US_set_distance(int d);
void DC_set_speed(int s);
#endif /* STATE_H_ */
