
#include "appConfig.h"


/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();

    DACDriverInit();
    sensorsCANInit(1000000);


    PRINTF("Task CAN RX Text\n");

    if (CANRxTaskInit() != pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while(1){};
    }

    if (DACTaskInit() != pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while(1){};
    }


    vTaskStartScheduler();

    while(1){};

    return (0);

}

