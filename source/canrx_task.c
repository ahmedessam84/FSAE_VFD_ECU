
#include "appConfig.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
TaskHandle_t CANRxTaskHandle;
extern volatile bool errFlag;

/* Task priorities. */
#define CANRx_task_PRIORITY (configMAX_PRIORITIES - 1)

runtimeStat_t rtCANTask;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void CANRx_task(void *pvParameters);


BaseType_t CANRxTaskInit() {

    return xTaskCreate(CANRx_task, "CANRx_task", configMINIMAL_STACK_SIZE + 10, NULL, CANRx_task_PRIORITY, &CANRxTaskHandle);

}


/*!
 * @brief Task responsible for storing select data received from CAN bus.
 * CANTask Execution Time 47 us
 */
static void CANRx_task(void *pvParameters)
{

    static sensor_t sensors= {0} ;

    const TickType_t xBlockTime = 1000; // block time set to 1 sec

    while(1)
    {
        //  block to wait for a notification from the ISR. This
        //  time however the first parameter is set to pdTRUE, clearing the task's
        //  notification value to 0, meaning each outstanding deferred
        //  interrupt event must be processed before ulTaskNotifyTake() is called
        //  again.

        ulTaskNotifyTake( pdTRUE, xBlockTime );
        // Wait for receiving the response from sensor

#ifdef RT_TEST
        rtCANTask.startTime = GET_RUN_TIME_COUNTER_VALUE();
#endif

        if(rxComplete){

            sensorsCANGetThrottle(&sensors);
            sensorsCANGetBrake(&sensors);
            sensorsCANGetSteering(&sensors);

#ifdef DB
            PRINTF(   "\nthrottle ADC: %5d", sensors.sensorThrottle.sensorADCThrottle);
            PRINTF("     throttle QEI: %5d", sensors.sensorThrottle.sensorQEIThrottle);

            PRINTF("     brake ADC: %5d", sensors.sensorBrake.sensorADCBrake);
            PRINTF("     brake QEI: %5d", sensors.sensorBrake.sensorQEIBrake);

            PRINTF("     steering: %5d\n", sensors.sensorADCSteering);
#endif

            rxComplete = false;

            xQueueSend( xThrottleQueue, ( void * ) &(sensors.sensorThrottle.sensorADCThrottle), ( TickType_t ) 0 );
            //xQueueSend( xThrottleQueue, ( void * ) &(sensors.sensorADCSteering), ( TickType_t ) 0 );

        }

        else if(errFlag == 1)
        {
#ifdef DB
            PRINTF(" error\n");
#endif
            errFlag = 0;
            sensors.sensorThrottle.sensorADCThrottle = 0;
        }

        // signal watchdog that task is alive
        Alive(0x1);

#ifdef RT_TEST
        rtCANTask.endTime = GET_RUN_TIME_COUNTER_VALUE();
        rtCANTask.execTime = rtCANTask.endTime - rtCANTask.startTime;
#endif

    }
}
