
#include "appConfig.h"

/******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool rxCompleteThrottle = false;
volatile bool rxCompleteBrake = false;
volatile bool rxCompleteSteering = false;
volatile bool rxComplete = false;

volatile bool errFlag = false;

flexcan_frame_t txFrame, RxMessage;

extern TaskHandle_t CANRxTaskHandle;

/*******************************************************************************
 * Code
 ******************************************************************************/

unsigned int BigToLitEndian(unsigned int x)
{
    return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}

/* An interrupt handler.  The interrupt handler does not perform any processing,
instead it unblocks a high priority task in which the event that generated the
interrupt is processed.  If the priority of the task is high enough then the
interrupt will return directly to the task (so it will interrupt one task but
return to a different task), so the processing will occur contiguously in time -
just as if all the processing had been done in the interrupt handler itself. */
void FLEXCAN_IRQHandler(void)
{

    BaseType_t xHigherPriorityTaskWoken;

    /* xHigherPriorityTaskWoken must be initialised to pdFALSE.  If calling
        vTaskNotifyGiveFromISR() unblocks the handling task, and the priority of
        the handling task is higher than the priority of the currently running task,
        then xHigherPriorityTaskWoken will automatically get set to pdTRUE. */

    xHigherPriorityTaskWoken = pdFALSE;

    /* If new data arrived. */
    if (FLEXCAN_GetMbStatusFlags(CAN0, 1 << RX_MB_THROTTLE))
    {
        FLEXCAN_ClearMbStatusFlags(CAN0, 1 << RX_MB_THROTTLE);
        rxCompleteThrottle = true;
        rxComplete = true;
        vTaskNotifyGiveFromISR( CANRxTaskHandle, &xHigherPriorityTaskWoken );

        /* If xHigherPriorityTaskWoken is now set to pdTRUE then a context switch
        should be performed to ensure the interrupt returns directly to the highest
        priority task.  The macro used for this purpose is dependent on the port in
        use and may be called portEND_SWITCHING_ISR(). */

        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );

    }
    // individual message interrupt commented out to reduce interrupt overhead and frequency
    // Only interrupt when throttle Msg is received and rely on the other messages being sent in a burst
    // right after.
/*
    else if (FLEXCAN_GetMbStatusFlags(CAN0, 1 << RX_MB_BRAKE))
    {
        FLEXCAN_ClearMbStatusFlags(CAN0, 1 << RX_MB_BRAKE);
        rxCompleteBrake = true;
        vTaskNotifyGiveFromISR( CANRxTaskHandle, &xHigherPriorityTaskWoken );
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );

    }

    else if (FLEXCAN_GetMbStatusFlags(CAN0, 1 << RX_MB_STEERING))
    {
        FLEXCAN_ClearMbStatusFlags(CAN0, 1 << RX_MB_STEERING);
        rxCompleteSteering = true;
        vTaskNotifyGiveFromISR( CANRxTaskHandle, &xHigherPriorityTaskWoken );
        portYIELD_FROM_ISR( xHigherPriorityTaskWoken );

    }
*/
    // error handling should be done here

    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
      exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif


}

void CANDriverMsgRxFilter(uint32_t id, uint32_t messageBufferNo) {

    flexcan_rx_mb_config_t mbConfig;
    /* Setup Rx Message Buffer. */
    mbConfig.format = kFLEXCAN_FrameFormatStandard;
    mbConfig.type = kFLEXCAN_FrameTypeData;
    mbConfig.id = FLEXCAN_ID_STD(id);
    FLEXCAN_SetRxMbConfig(CAN0, messageBufferNo, &mbConfig, true);
}

void CANDriverInit(uint32_t baudrate) {

    flexcan_config_t flexcanConfig;

    // baudrate set to 1Mbps by default
    FLEXCAN_GetDefaultConfig(&flexcanConfig);

    flexcanConfig.baudRate = baudrate;
    flexcanConfig.clkSrc = kFLEXCAN_ClkSrcPeri;

    FLEXCAN_Init(CAN0, &flexcanConfig, CAN_CLK_FREQ);
}

void CANDriverInterruptEnable(uint32_t mask){

    /* Enable Rx Message Buffer interrupt. */
    // interrupt priority can be set from (0-15)
    // default is 0 which is the highest priority
    NVIC_SetPriority(FLEXCAN_IRQn,15);
    FLEXCAN_EnableMbInterrupts(CAN0, mask);
    EnableIRQ(FLEXCAN_IRQn);

}


// Receive Message needs to be called after rx interrupt happens
void CANDriverMsgReceive(uint32_t messageBufferNo, flexcan_frame_t* msg_ptr) {

    FLEXCAN_ReadRxMb(CAN0, messageBufferNo, msg_ptr);
    //rxComplete = false;
    //return RxMessage;
}
