/*
 * dac_task.c
 *
 *  Created on: Mar 5, 2018
 *      Author: ahmed
 */

#include "appConfig.h"

// safety mechanism
// set output to zero if no reading is received for any reason
#define SAFETY_TIMEOUT   500

/*******************************************************************************
 * Definitions
 ******************************************************************************/
TaskHandle_t DACTaskHandle;

QueueHandle_t xThrottleQueue;

runtimeStat_t rtDACTask;

/* Task priorities. */
#define DAC_task_PRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DAC_task(void *pvParameters);


BaseType_t DACTaskInit() {

    // create a queue for message passing between tasks
    xThrottleQueue = xQueueCreate( 1, sizeof( uint32_t ) );

    return xTaskCreate(DAC_task, "DAC_task", configMINIMAL_STACK_SIZE + 10, NULL, DAC_task_PRIORITY, &DACTaskHandle);

}


/*!
 * @brief Task responsible for analog output to the VFD.
 * DACTask Execution Time 7 us
 */
static void DAC_task(void *pvParameters)
{

    static uint32_t throttleReading = 0;

    while(1)
    {
        // Receive a message from the created queue.
        // the message is being sent from the CANRx_Task --> DAC_Task
        if( xQueueReceive( xThrottleQueue, &( throttleReading ), ( TickType_t ) SAFETY_TIMEOUT ) )
        {

#ifdef RT_TEST
            rtDACTask.startTime = GET_RUN_TIME_COUNTER_VALUE();
#endif
            DACDriverOutputSet(throttleReading);
        }
        else
        {
            // Error handling if for any reason a reading is not received turn off the output
            DACDriverOutputSet(0);
        }

        // signal watchdog that task is alive
        Alive(0x2);

#ifdef RT_TEST
        rtDACTask.endTime = GET_RUN_TIME_COUNTER_VALUE();
        rtDACTask.execTime = rtDACTask.endTime - rtDACTask.startTime;
#endif

    }

}
