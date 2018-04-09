/*
 * lptimer_driver.h
 *
 *  Created on: Mar 14, 2018
 *      Author: ahmed
 */

#ifndef RUNTIME_TIMER_API_H_
#define RUNTIME_TIMER_API_H_

extern volatile unsigned long ulHighFrequencyTimerTicks;

void RuntimeTimerInit(void);

#endif /* RUNTIME_TIMER_API_H_ */
