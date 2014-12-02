################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: MyLPC812_Checker_board.axf

dependents:
	-cd C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/CMSIS_CORE_LPC8xx/Debug && $(MAKE) all
	-cd C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/lpc800_driver_lib/Debug && $(MAKE) all

# Tool invocations
MyLPC812_Checker_board.axf: $(OBJS) $(USER_OBJS) C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/CMSIS_CORE_LPC8xx/Debug/libCMSIS_CORE_LPC8xx.a C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/lpc800_driver_lib/Debug/liblpc800_driver_lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\lpc800_driver_lib\Debug" -L"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\CMSIS_CORE_LPC8xx\Debug" -L"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\CMSIS_DSPLIB_CM0\lib" -Xlinker -Map="MyLPC812_Checker_board.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "MyLPC812_Checker_board_Debug.ld" -o "MyLPC812_Checker_board.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) MyLPC812_Checker_board.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "MyLPC812_Checker_board.axf"; # arm-none-eabi-objcopy -v -O binary "MyLPC812_Checker_board.axf" "MyLPC812_Checker_board.bin" ; # checksum -p LPC812 -d "MyLPC812_Checker_board.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/CMSIS_CORE_LPC8xx/Debug/libCMSIS_CORE_LPC8xx.a:
C:/Users/Hikaru/Documents/LPCXpresso_7.4.0_229/workspace3/lpc800_driver_lib/Debug/liblpc800_driver_lib.a:

-include ../makefile.targets
