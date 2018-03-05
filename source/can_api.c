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

    // mask changed for testing to interrupt for only one message
    // individual message interrupt commented out to reduce interrupt overhead and frequency
    // Only interrupt when throttle Msg is received and rely on the other messages being sent in a burst
    // right after.
    // if you want to interrupt for all change the argument to RX_MB_MASK without the left shift operator
    CANDriverInterruptEnable(RX_MB_MASK);

}


void CANAPIMsgReceiveThrottle(sensorThrottle_t * data_ptr){

    flexcan_frame_t throttleFrame;
    throttleFrame = CANDriverMsgReceive(RX_MB_THROTTLE);

    rxCompleteThrottle = false;

    // CONVERT TO LITTLE ENDIAN
    throttleFrame.dataWord0 = BIG_TO_LIT_ENDIAN(throttleFrame.dataWord0);
    throttleFrame.dataWord1 = BIG_TO_LIT_ENDIAN(throttleFrame.dataWord1);

    // Extract information from frame
    data_ptr->sensorADCThrottle = throttleFrame.dataWord0;
    data_ptr->sensorQEIThrottle = throttleFrame.dataWord1;

}


void CANAPIMsgReceiveBrake(sensorBrake_t * data_ptr){

    flexcan_frame_t brakeFrame;
    brakeFrame = CANDriverMsgReceive(RX_MB_BRAKE);

    rxCompleteBrake = false;

    // CONVERT TO LITTLE ENDIAN
    brakeFrame.dataWord0 = BIG_TO_LIT_ENDIAN(brakeFrame.dataWord0);
    brakeFrame.dataWord1 = BIG_TO_LIT_ENDIAN(brakeFrame.dataWord1);

    // Extract information from frame
    data_ptr->sensorADCBrake = brakeFrame.dataWord0;
    data_ptr->sensorQEIBrake = brakeFrame.dataWord1;

    //PRINTF("\n%d", brakeFrame.dataByte0);

}


void CANAPIMsgReceiveSteering(uint32_t * data_ptr){

    flexcan_frame_t steeringFrame;
    steeringFrame = CANDriverMsgReceive(RX_MB_STEERING);

    rxCompleteSteering = false;

    steeringFrame.dataWord0 = BIG_TO_LIT_ENDIAN(steeringFrame.dataWord0);

    *data_ptr = steeringFrame.dataWord0;
    //PRINTF("\n%d", steeringFrame.dataByte0);

}



