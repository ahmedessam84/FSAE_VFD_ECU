
#include "appConfig.h"


/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

#ifdef DB
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    DACDriverInit();
    sensorsCANInit(1000000);


#ifdef DB
    PRINTF("Task CAN RX Text\n");
#endif

#ifdef RT_TEST
    //
    // Create the runtime stats task.
    //
    if(RunTimeStatsTask_Init() !=0)
    {
        while(1)
        {
            // error task creation failed
        }
    }
#endif

    if (CANRxTaskInit() != pdPASS)
    {
#ifdef DB
        PRINTF("Task creation failed!.\r\n");
#endif
        while(1){};
    }

    if (DACTaskInit() != pdPASS)
    {
#ifdef DB
        PRINTF("Task creation failed!.\r\n");
#endif
        while(1){};
    }

    if (WatchdogTaskInit() != pdPASS)
    {
#ifdef DB
        PRINTF("Task creation failed!.\r\n");
#endif
        while(1){};
    }

    vTaskStartScheduler();

    while(1){};

    return (0);

}

