/*
 * can_api.c
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#include "appConfig.h"


// initialize the driver to recieve three messages from teh bus with the ids above from the Message Buffer numbers above
void CANAPIInit (uint32_t b) {

    CANDriverInit(b);

    // This is the place to add more ids for the CAN module to listen to
    CANDriverMsgRxFilter(CAN_THROTTLE_ID, RX_MB_THROTTLE);
    CANDriverMsgRxFilter(CAN_BRAKE_ID, RX_MB_BRAKE);
    CANDriverMsgRxFilter(CAN_STEERING_ID, RX_MB_STEERING);

    // adjust the mask in can_driver.h to the interrupt you want
    CANDriverInterruptEnable(RX_MB_MASK);

}


void CANAPIMsgReceiveThrottle(sensorThrottle_t * data_ptr){

    flexcan_frame_t throttleFrame = {0};

    CANDriverMsgReceive(RX_MB_THROTTLE, &throttleFrame);

    rxCompleteThrottle = false;

    // Extract information from frame
    data_ptr->sensorADCThrottle = BIG_TO_LIT_ENDIAN(throttleFrame.dataWord0); // CONVERT TO LITTLE ENDIAN
    data_ptr->sensorQEIThrottle = BIG_TO_LIT_ENDIAN(throttleFrame.dataWord1); // CONVERT TO LITTLE ENDIAN

}


void CANAPIMsgReceiveBrake(sensorBrake_t * data_ptr){

    flexcan_frame_t brakeFrame = {0};
    CANDriverMsgReceive(RX_MB_BRAKE, &brakeFrame);

    rxCompleteBrake = false;

    // Extract information from frame
    data_ptr->sensorADCBrake = BIG_TO_LIT_ENDIAN(brakeFrame.dataWord0); // CONVERT TO LITTLE ENDIAN
    data_ptr->sensorQEIBrake = BIG_TO_LIT_ENDIAN(brakeFrame.dataWord1); // CONVERT TO LITTLE ENDIAN

    //PRINTF("\n%d", brakeFrame.dataByte0);

}


void CANAPIMsgReceiveSteering(uint32_t * data_ptr){

    flexcan_frame_t steeringFrame = {0};
    CANDriverMsgReceive(RX_MB_STEERING, &steeringFrame);

    rxCompleteSteering = false;

    steeringFrame.dataWord0 = BIG_TO_LIT_ENDIAN(steeringFrame.dataWord0);

    *data_ptr = steeringFrame.dataWord0;

    //PRINTF("\n%d", steeringFrame.dataByte0);

}



