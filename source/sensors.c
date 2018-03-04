/*
 * sensors.c
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#include "appConfig.h"

void sensorsCANInit(uint32_t baud){

    CANAPIInit(baud);

}

void sensorsCANGetThrottle(sensor_t * sensors){

    CANAPIMsgReceiveThrottle(&sensors->sensorThrottle);

}

void sensorsCANGetBrake(sensor_t * sensors){

    CANAPIMsgReceiveBrake(&sensors->sensorBrake);

}


void sensorsCANGetSteering(sensor_t * sensors){

    CANAPIMsgReceiveSteering(&sensors->sensorADCSteering);

}



