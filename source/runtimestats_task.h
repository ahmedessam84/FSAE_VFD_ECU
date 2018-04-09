/*
 * runtimestats_task.h
 *
 *  Created on: Mar 15, 2018
 *      Author: ahmed
 */

#ifndef RUNTIMESTATS_TASK_H_
#define RUNTIMESTATS_TASK_H_

#define     GET_RUN_TIME_COUNTER_VALUE()        ulHighFrequencyTimerTicks

typedef struct{
    unsigned long startTime;
    unsigned long endTime;
    unsigned long execTime;
} runtimeStat_t;

BaseType_t RunTimeStatsTask_Init(void);

#endif /* RUNTIMESTATS_TASK_H_ */
