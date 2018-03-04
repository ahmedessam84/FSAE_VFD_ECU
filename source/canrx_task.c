
#include "appConfig.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
TaskHandle_t CANRxTaskHandle;
extern volatile bool rxComplete;
extern volatile bool errFlag;

/* Task priorities. */
#define CANRx_task_PRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void CANRx_task(void *pvParameters);


BaseType_t CANRxTaskInit() {

    sensorsCANInit(1000000);
    return xTaskCreate(CANRx_task, "CANRx_task", configMINIMAL_STACK_SIZE + 10, NULL, CANRx_task_PRIORITY, &CANRxTaskHandle);

}


/*!
 * @brief Task responsible for storing select data received from CAN bus.
 */
static void CANRx_task(void *pvParameters)
{

    sensor_t sensors;

    const TickType_t xBlockTime = 4000; // block time set to 4 sec

    while(1)
    {
        //  block to wait for a notification from the ISR. This
        //  time however the first parameter is set to pdTRUE, clearing the task's
        //  notification value to 0, meaning each outstanding deferred
        //  interrupt event must be processed before ulTaskNotifyTake() is called
        //  again.

        ulTaskNotifyTake( pdTRUE, xBlockTime );
        // Wait for receiving the response from sensor

        if(rxCompleteThrottle)
        {
            sensorsCANGetThrottle(&sensors);
        }
        else if(rxCompleteBrake)
        {
            sensorsCANGetBrake(&sensors);
        }
        else if(rxCompleteSteering)
        {
            sensorsCANGetSteering(&sensors);
        }
        else if(errFlag == 1)
        {
            PRINTF(" error\n");
            errFlag = 0;
        }

        //PRINTF("\r\nId: %d, -- length: %d, -- Msg: %d", CONVERT_ID(receivedMsg.id), receivedMsg.length, ui32Data);

        PRINTF("\nthrottle: %d, brake: %d, steering: %d", sensors.sensorThrottle.sensorADCThrottle, sensors.sensorBrake.sensorADCBrake, sensors.sensorADCSteering);

    }
}
