################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/can_api.c \
../source/can_driver.c \
../source/canrx_task.c \
../source/main.c \
../source/semihost_hardfault.c \
../source/sensors.c 

OBJS += \
./source/can_api.o \
./source/can_driver.o \
./source/canrx_task.o \
./source/main.o \
./source/semihost_hardfault.o \
./source/sensors.o 

C_DEPS += \
./source/can_api.d \
./source/can_driver.d \
./source/canrx_task.d \
./source/main.d \
./source/semihost_hardfault.d \
./source/sensors.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"D:\workspace_nxp\K64_freertosRX\board" -I"D:\workspace_nxp\K64_freertosRX\source" -I"D:\workspace_nxp\K64_freertosRX" -I"D:\workspace_nxp\K64_freertosRX\freertos\include" -I"D:\workspace_nxp\K64_freertosRX\freertos\portable" -I"D:\workspace_nxp\K64_freertosRX\drivers" -I"D:\workspace_nxp\K64_freertosRX\CMSIS" -I"D:\workspace_nxp\K64_freertosRX\utilities" -I"D:\workspace_nxp\K64_freertosRX\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


