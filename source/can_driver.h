/*
 * can_driver.h
 *
 *  Created on: Feb 23, 2018
 *      Author: ahmed
 */

#ifndef CAN_DRIVER_H_
#define CAN_DRIVER_H_

#include "fsl_flexcan.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CAN                     CAN0
#define CAN_CLKSRC              kCLOCK_BusClk
#define CAN_CLK_FREQ            CLOCK_GetFreq(kCLOCK_BusClk)
#define FLEXCAN_IRQn            CAN0_ORed_Message_buffer_IRQn
#define FLEXCAN_IRQHandler      CAN0_ORed_Message_buffer_IRQHandler

#define RX_MB_THROTTLE          (6)
#define RX_MB_BRAKE             (7)
#define RX_MB_STEERING          (8)
#define RX_MB_MASK              (1<<RX_MB_THROTTLE) /*| (1<<RX_MB_BRAKE) | (1<<RX_MB_STEERING)*/

#define TX_MESSAGE_BUFFER_NUM   (9)


#define CONVERT_ID(id)          ((uint32_t)(((uint32_t)(id)) >> CAN_ID_STD_SHIFT))
#define BIG_TO_LIT_ENDIAN(x)       (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000))



extern volatile bool rxCompleteThrottle;
extern volatile bool rxCompleteBrake;
extern volatile bool rxCompleteSteering;
extern volatile bool rxComplete;




void CANDriverInit(uint32_t baudrate);
void CANDriverInterruptEnable(uint32_t mask);
void CANDriverMsgReceive(uint32_t messageBufferNo, flexcan_frame_t* msg_ptr);
void CANDriverMsgRxFilter(uint32_t id, uint32_t messageBufferNo);




#endif /* CAN_DRIVER_H_ */
