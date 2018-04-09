/*
 * appConfig.h
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#ifndef APPCONFIG_H_
#define APPCONFIG_H_

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/**
 * @file    K64_freertosRX.c
 * @brief   Application entry point.
 */

/*Standard C library*/
#include <stdio.h>


/* Freescale includes. */
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_flexcan.h"
#include "fsl_dac.h"
#include "fsl_wdog.h"
#include "fsl_rcm.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lptmr.h"
#include "fsl_pit.h"


/* Firmware */
#include "can_driver.h"
#include "dac_driver.h"


/* Middleware */
#include "sensors.h"
#include "can_api.h"
#include "watchdog_api.h"
#include "runtime_timer_api.h"

/* Tasks */
#include "canrx_task.h"
#include "dac_task.h"
#include "watchdog_task.h"
#include "runtimestats_task.h"


/* Enable/Disable debug mode */
//#define DB

/* Enable/Disable runtime stats tests */
//#define RT_TEST

#endif /* APPCONFIG_H_ */
