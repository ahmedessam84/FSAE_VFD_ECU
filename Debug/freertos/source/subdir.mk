################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/source/croutine.c \
../freertos/source/event_groups.c \
../freertos/source/list.c \
../freertos/source/queue.c \
../freertos/source/tasks.c \
../freertos/source/timers.c 

OBJS += \
./freertos/source/croutine.o \
./freertos/source/event_groups.o \
./freertos/source/list.o \
./freertos/source/queue.o \
./freertos/source/tasks.o \
./freertos/source/timers.o 

C_DEPS += \
./freertos/source/croutine.d \
./freertos/source/event_groups.d \
./freertos/source/list.d \
./freertos/source/queue.d \
./freertos/source/tasks.d \
./freertos/source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/source/%.o: ../freertos/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DPRINTF_FLOAT_ENABLE=0 -D__USE_CMSIS -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\drivers" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\CMSIS" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\board" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\source" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\freertos\include" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\freertos\portable" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\utilities" -I"D:\workspace_nxp\FSAE_VFD_ECU_K64\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


