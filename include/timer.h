/*
 * timer.h
 *
 *  Created on: 27 May 2018
 *      Author: GOKU
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <alt_types.h>

struct Timer{
	alt_u32 timer_base;
	void (*clrTO)(struct Timer*);
#ifdef FULL_PERIPH
	alt_u16 (*getSR)(struct Timer*);
	void (*clrCR)(struct Timer*);
	void (*setITO)(struct Timer*);
	void (*clrITO)(struct Timer*);
	void (*setContinuous)(struct Timer*);
	void (*clrContinuous)(struct Timer*);
	void (*setStart)(struct Timer*);
	void (*setStop)(struct Timer*);
	alt_u16 (*getTO)(struct Timer*);
	alt_u16 (*getRUN)(struct Timer*);
	void (*setPeriod)(struct Timer*, alt_u32);
	alt_u32 (*getSnap)(struct Timer*);
#else
	void (*init)(struct Timer*, alt_u8, alt_u8, alt_u8, alt_u32);
#endif
};

extern const struct TimerClass{
	struct Timer(*new)(alt_u32 base);
}Timer;

#endif /* TIMER_H_ */
