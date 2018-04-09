/*
 * watchdog_api.c
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmed
 */

#include "appConfig.h"

/*******************************************************************************
* Variables
******************************************************************************/
static WDOG_Type *wdog_base = WDOG;
volatile uint32_t watch_flag = 0;



/*!
 * @brief Checks if all the tasks signalled their alive flags
 * @param x is the specific task flag
 */
void Alive(uint32_t x){

    taskENTER_CRITICAL();
    watch_flag |= x;
    taskEXIT_CRITICAL();

}

/*!
 * @brief WatchDog Initialization
 */
void watchdogInit(void) {

    wdog_config_t config;

    /*
     * config.enableWdog = true;
     * config.clockSource = kWDOG_LpoClockSource;
     * config.prescaler = kWDOG_ClockPrescalerDivide1;
     * config.enableUpdate = true;
     * config.enableInterrupt = false;
     * config.enableWindowMode = false;
     * config.windowValue = 0U;
     * config.timeoutValue = 0xFFFFU;
     */

    WDOG_GetDefaultConfig(&config);

    // 2047 ms with a 1kHz clock (kWDOG_LpoClockSource)
    // set to 2 sec when in normal mode
    config.timeoutValue = 0x7ffU;

#ifdef DB
    // set to 4 sec when in debugging mode
    config.timeoutValue = 0xFA0U;
#endif

    WDOG_Init(wdog_base, &config);

}

/*!
 * #brief Resets the Watchdog time
 */
void watchdogKick(){
    WDOG_Refresh(wdog_base);
}
