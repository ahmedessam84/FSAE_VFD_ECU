/*
 * can_api.c
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#include "appConfig.h"

// configuration
const uint32_t MB[] = {RX_MB_THROTTLE,RX_MB_BRAKE,RX_MB_STEERING};
const uint32_t CAN_ID[] = {CAN_THROTTLE_ID, CAN_BRAKE_ID, CAN_STEERING_ID};


// initialize the driver to recieve three messages from teh bus with the ids above from the Message Buffer numbers above
void CANAPIInit (uint32_t b) {

    int size;

    size = (sizeof(MB))/(sizeof(MB[0]));

    CANDriverInit(b);

    // Set the filter to select the defined IDs above
    int i;
    for(i=0;i<size;i++){
        CANDriverMsgRxFilter(CAN_ID[i], MB[i]);
    }

    CANDriverInterruptEnable(RX_MB_MASK);

}


void CANAPIMsgReceiveThrottle(uint32_t * data_ptr){

    flexcan_frame_t throttleFrame;
    throttleFrame = CANDriverMsgReceive(MB[0]);

    rxCompleteThrottle = false;

    data_ptr = &throttleFrame.dataByte0;
    //PRINTF("\n%d", throttleFrame.dataByte0);

}


void CANAPIMsgReceiveBrake(uint32_t * data_ptr){

    flexcan_frame_t brakeFrame;
    brakeFrame = CANDriverMsgReceive(MB[1]);

    rxCompleteBrake = false;

    data_ptr = &brakeFrame.dataWord0;
    //PRINTF("\n%d", brakeFrame.dataByte0);

}


void CANAPIMsgReceiveSteering(uint32_t * data_ptr){

    flexcan_frame_t steeringFrame;
    steeringFrame = CANDriverMsgReceive(MB[2]);

    rxCompleteSteering = false;

    data_ptr = &steeringFrame.dataWord0;
    //PRINTF("\n%d", steeringFrame.dataByte0);

}



