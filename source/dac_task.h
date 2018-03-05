/*
 * dac_task.h
 *
 *  Created on: Mar 5, 2018
 *      Author: ahmed
 */

#ifndef DAC_TASK_H_
#define DAC_TASK_H_

extern QueueHandle_t xThrottleQueue;

BaseType_t DACTaskInit(void);

#endif /* DAC_TASK_H_ */
