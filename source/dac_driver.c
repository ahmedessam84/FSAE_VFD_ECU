/*
 * dac_driver.c
 *
 *  Created on: Mar 5, 2018
 *      Author: ahmed
 */

#include "appConfig.h"


/*
 *
 * DAC_OUT pin 11 used
 *
 */


#define DAC_BASEADDR    DAC0


dac_config_t dacConfigStruct;

void DACDriverInit(void){

    /* Configure the DAC. */
    /*
     * dacConfigStruct.referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2;
     * dacConfigStruct.enableLowPowerMode = false;
     */
    DAC_GetDefaultConfig(&dacConfigStruct);
    DAC_Init(DAC_BASEADDR, &dacConfigStruct);
    DAC_Enable(DAC_BASEADDR, true);             /* Enable output. */
    DAC_SetBufferReadPointer(DAC_BASEADDR, 0U); /* Make sure the read pointer to the start. */

}

void DACDriverOutputSet(uint32_t data){
    /*
    * The value in the item would be converted. User can measure the output voltage from DAC_OUTx pin.
    */
    DAC_SetBufferValue(DAC_BASEADDR, 0U, data);

}
