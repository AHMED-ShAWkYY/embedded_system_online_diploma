################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.c \
../stm32_f103c6_drivers/stm32f103c6_gpio_driver.c 

OBJS += \
./stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.o \
./stm32_f103c6_drivers/stm32f103c6_gpio_driver.o 

C_DEPS += \
./stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.d \
./stm32_f103c6_drivers/stm32f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.o: ../stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/PC/STM32CubeIDE/workspace_1.4.0/drivers/stm32_f103c6_drivers/inc" -I"C:/Users/PC/STM32CubeIDE/workspace_1.4.0/drivers/stm32_f103c6_drivers/keypad_driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/stm32f103c6_EXTI_driver2.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_f103c6_drivers/stm32f103c6_gpio_driver.o: ../stm32_f103c6_drivers/stm32f103c6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/PC/STM32CubeIDE/workspace_1.4.0/drivers/stm32_f103c6_drivers/inc" -I"C:/Users/PC/STM32CubeIDE/workspace_1.4.0/drivers/stm32_f103c6_drivers/keypad_driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_drivers/stm32f103c6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

