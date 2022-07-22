/*
 * memmap.h
 *
 * Created: 7/22/2022 11:06:57 AM
 *  Author: PC
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define DDRA *((unsigned char *)(0x3A))
#define PORTA *((unsigned char *)(0x3B))
#define PINA *((unsigned char *)(0x39))

#define DDRB *((unsigned char *)(0x37))
#define PORTB *((unsigned char *)(0x38))
#define PINB *((unsigned char *)(0x36))


#define DDRD *((unsigned char *)(0x31))
#define PORTD *((unsigned char *)(0x32))
#define PIND *((unsigned char *)(0x30))

#endif /* MEMMAP_H_ */