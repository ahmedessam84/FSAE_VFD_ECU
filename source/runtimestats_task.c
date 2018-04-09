/*
 * runtimestats_task.c
 *
 *  Created on: Mar 15, 2018
 *      Author: ahmed
 */

#include "appConfig.h"


/* Execution time calculation variables */
extern runtimeStat_t rtCANTask;
extern runtimeStat_t rtDACTask;
extern runtimeStat_t rtWDTask;




//*****************************************************************************
//
// Runtime stats collection task
//
//*****************************************************************************

TaskHandle_t runtimeStatTask_Handle = NULL;

void RuntimeStatTask( void * pvParameters ){
    while(1){

        // Customize according to the tasks available in the application
        PRINTF("\n\nCANTask Execution Time %d us", rtCANTask.execTime);
        PRINTF("\nDACTask Execution Time %d us",   rtDACTask.execTime);
        PRINTF("\nWATCHDOGTask Execution Time %d us",   rtWDTask.execTime);
        vTaskDelay(2000);

    }
}



BaseType_t RunTimeStatsTask_Init( void ){

    RuntimeTimerInit();

    if( xTaskCreate(RuntimeStatTask, "RuntimeStatTask", 200, NULL, 1 /*PRIORITY_CANTX_TASK*/, &runtimeStatTask_Handle) != pdTRUE )
    {
        return (1);
    }
    else return (0);

}
