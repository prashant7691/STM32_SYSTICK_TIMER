################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SW_LED_PJN.c \
../src/main.c \
../src/serial_io.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/SW_LED_PJN.o \
./src/main.o \
./src/serial_io.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/SW_LED_PJN.d \
./src/main.d \
./src/serial_io.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F407IGHx -DSTM3240G_EVAL -DSTM32 -DSTM32F4 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F40XX -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib" -I"C:/Users/namekarp/workspace/SYSTICK_DELAY_PJN_1/inc" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/CMSIS/core" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/CMSIS/device" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/StdPeriph_Driver/inc" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/Utilities/Common" -I"C:/Users/namekarp/workspace/stm3240g-eval_stdperiph_lib/Utilities/STM3240_41_G_EVAL" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


