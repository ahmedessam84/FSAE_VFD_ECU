/*
 * watchdog_task.c
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmed
 */


#include "appConfig.h"

TaskHandle_t Watchdog_Task_Handle = NULL;

static void Watchdog_Task(void* pvParameters);

runtimeStat_t rtWDTask;

BaseType_t WatchdogTaskInit(void){

    watchdogInit();

    return (xTaskCreate( Watchdog_Task, "Watchdog_Task", configMINIMAL_STACK_SIZE + 10, NULL, 1 /*PRIORITY_Watchdog_TASK*/, &Watchdog_Task_Handle ));

}

/*!
 *
 * WATCHDOGTask Execution Time 3 us
 */
static void Watchdog_Task(void * pvParameters) {

    // Run this task every 500 ms
    // If the task does not run on time the watchdog will reset the system

    TickType_t xLastWakeTime = NULL;

    // Initialize the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    while(1){

        vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS( 500 ) );

#ifdef RT_TEST
        rtWDTask.startTime = GET_RUN_TIME_COUNTER_VALUE();
#endif

        // If all tasks are alive kick the watchdog
        if (watch_flag == (0x3))
        {
            watchdogKick();     // Kick the watchdog
            watch_flag = 0;     // Erase flags
        }

#ifdef RT_TEST
        rtWDTask.endTime = GET_RUN_TIME_COUNTER_VALUE();
        rtWDTask.execTime = rtWDTask.endTime - rtWDTask.startTime;
#endif

    }

}
