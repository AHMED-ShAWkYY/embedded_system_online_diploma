/*
 * utils.h
 *
 * Created: 7/22/2022 11:24:21 AM
 *  Author: PC
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define setbit(reg,bitno) reg|=(1<<bitno) 
#define clearbit(reg,bitno) reg&=~(1<<bitno)
#define getbit(reg,bitno) ((reg>>bitno)&1)
#define togglebit(reg,bitno) reg^=(1<<bitno)


#endif /* UTILS_H_ */