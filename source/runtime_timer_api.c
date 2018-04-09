/*
 * lptimer_api.c
 *
 *  Created on: Mar 14, 2018
 *      Author: ahmed
 */

/*!
 * This timer is being used in the project for runtime stats only.
 */

#include "appConfig.h"


#define RuntimeTimerIntHandler PIT0_IRQHandler

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile unsigned long ulHighFrequencyTimerTicks = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/
void RuntimeTimerIntHandler(void)
{
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    ulHighFrequencyTimerTicks++;
    /*
     * Workaround for TWR-KV58: because write buffer is enabled, adding
     * memory barrier instructions to make sure clearing interrupt flag completed
     * before go out ISR
     */
    __DSB();
    __ISB();
}

/*!
 * @brief Initializes timer 1 to be used by the RTOS for runtime stats
 */
void RuntimeTimerInit(void)
{
    pit_config_t config;
    PIT_GetDefaultConfig(&config);
    PIT_Init(PIT, &config);
    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1, CLOCK_GetFreq(kCLOCK_BusClk) ));
    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
    EnableIRQ(PIT0_IRQn);
    PIT_StartTimer(PIT, kPIT_Chnl_0);
}
