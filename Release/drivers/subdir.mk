################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_dac.c \
../drivers/fsl_flash.c \
../drivers/fsl_flexcan.c \
../drivers/fsl_gpio.c \
../drivers/fsl_rcm.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c \
../drivers/fsl_wdog.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dac.o \
./drivers/fsl_flash.o \
./drivers/fsl_flexcan.o \
./drivers/fsl_gpio.o \
./drivers/fsl_rcm.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_wdog.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dac.d \
./drivers/fsl_flash.d \
./drivers/fsl_flexcan.d \
./drivers/fsl_gpio.d \
./drivers/fsl_rcm.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d \
./drivers/fsl_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DNDEBUG -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\drivers" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\CMSIS" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\board" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\source" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\freertos\include" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\freertos\portable" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\utilities" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\startup" -Os -fno-common -g -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


