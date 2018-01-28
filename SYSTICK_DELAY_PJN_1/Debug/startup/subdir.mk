################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f40xx.s 

OBJS += \
./startup/startup_stm32f40xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib" -I"C:/Users/namekarp/workspace/SYSTICK_DELAY_PJN_1/inc" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/CMSIS/core" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/CMSIS/device" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/StdPeriph_Driver/inc" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/Utilities/Common" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/Utilities/STM3240_41_G_EVAL" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


