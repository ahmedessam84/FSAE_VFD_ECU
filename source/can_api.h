/*
 * can_api.h
 *
 *  Created on: Mar 4, 2018
 *      Author: ahmed
 */

#ifndef CAN_API_H_
#define CAN_API_H_

/***********************************************************************/
#define CAN_OBJ_THROTTLE    2
#define CAN_OBJ_BRAKE       3
#define CAN_OBJ_STEERING    4

// CAN ID = ECU_NODE_NUMBER + SENSOR_ID
#define ECU_NODE_NUMBER     100

#define THROTTLE_ID         1
#define BRAKE_ID            2
#define STEERING_ID         3

#define CAN_THROTTLE_ID     (ECU_NODE_NUMBER + THROTTLE_ID)
#define CAN_BRAKE_ID        (ECU_NODE_NUMBER + BRAKE_ID)
#define CAN_STEERING_ID     (ECU_NODE_NUMBER + STEERING_ID)


/*************************************************************************/


void CANAPIInit(uint32_t b);
void CANAPIMsgReceiveThrottle(sensorThrottle_t * data_ptr);
void CANAPIMsgReceiveBrake(sensorBrake_t * data_ptr);
void CANAPIMsgReceiveSteering(uint32_t * data_ptr);


#endif /* CAN_API_H_ */
