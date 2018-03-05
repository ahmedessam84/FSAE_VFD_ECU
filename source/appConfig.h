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
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_flexcan.h"
#include "fsl_dac.h"


/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"


/* Firmware */
#include "can_driver.h"
#include "dac_driver.h"


/* Middleware */
#include "sensors.h"
#include "can_api.h"


/* Tasks */
#include "canrx_task.h"
#include "dac_task.h"


#endif /* APPCONFIG_H_ */
