################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MyLPC812.c \
../src/cr_startup_lpc8xx.c \
../src/crp.c \
../src/mtb.c \
../src/sct_fsm.c 

OBJS += \
./src/MyLPC812.o \
./src/cr_startup_lpc8xx.o \
./src/crp.o \
./src/mtb.o \
./src/sct_fsm.o 

C_DEPS += \
./src/MyLPC812.d \
./src/cr_startup_lpc8xx.d \
./src/crp.d \
./src/mtb.d \
./src/sct_fsm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_CMSIS=CMSIS_CORE_LPC8xx -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM0 -D__LPC8XX__ -D__REDLIB__ -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\lpc800_driver_lib" -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\CMSIS_CORE_LPC8xx" -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\MyLPC812_Checker_board\inc" -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\CMSIS_CORE_LPC8xx\inc" -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\CMSIS_DSPLIB_CM0\inc" -I"C:\Users\Hikaru\Documents\LPCXpresso_7.4.0_229\workspace3\lpc800_driver_lib\inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


