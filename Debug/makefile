################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include freertos/source/subdir.mk
-include freertos/portable/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FSAE_VFD_ECU_K64.axf

# Tool invocations
FSAE_VFD_ECU_K64.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -print-memory-usage -Xlinker --gc-sections -Xlinker -Map="FSAE_VFD_ECU_K64.map" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -T "FSAE_VFD_ECU_K64_Debug.ld" -o "FSAE_VFD_ECU_K64.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FSAE_VFD_ECU_K64.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FSAE_VFD_ECU_K64.axf"; # arm-none-eabi-objcopy -v -O binary "FSAE_VFD_ECU_K64.axf" "FSAE_VFD_ECU_K64.bin" ; # checksum -p MK64FN1M0xxx12 -d "FSAE_VFD_ECU_K64.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
