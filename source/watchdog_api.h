/*
 * watchdog_api.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmed
 */

#ifndef WATCHDOG_API_H_
#define WATCHDOG_API_H_

extern volatile uint32_t watch_flag;

void Alive(uint32_t x);
void watchdogInit();
void watchdogKick();

#endif /* WATCHDOG_API_H_ */
