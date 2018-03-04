/*
 * sensors.h
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#ifndef SENSORS_H_
#define SENSORS_H_

typedef struct {

    struct  {
        uint32_t sensorADCThrottle;
        uint32_t sensorQEIThrottle;
    } sensorThrottle;

    struct  {
        uint32_t sensorADCBrake;
        uint32_t sensorQEIBrake;
    } sensorBrake;

    uint32_t sensorADCSteering;

} sensor_t;


void sensorsCANInit(uint32_t baud);
void sensorsCANGetThrottle(sensor_t * sensors);
void sensorsCANGetBrake(sensor_t * sensors);
void sensorsCANGetSteering(sensor_t * sensors);


#endif /* SENSORS_H_ */
