################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middleware/led.c \
../middleware/light_sensor.c \
../middleware/queue.c 

C_DEPS += \
./middleware/led.d \
./middleware/light_sensor.d \
./middleware/queue.d 

OBJS += \
./middleware/led.o \
./middleware/light_sensor.o \
./middleware/queue.o 


# Each subdirectory must supply rules for building sources it contributes
middleware/%.o: ../middleware/%.c middleware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -I"D:\MCU_E\workplace\app2\CMSIS" -I"D:\MCU_E\workplace\app2\middleware" -I"D:\MCU_E\workplace\app2\MKL46_Driver" -I"D:\MCU_E\workplace\app2\source" -I"D:\MCU_E\workplace\app2\startup" -O0 -fno-common -g -gdwarf-4 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-middleware

clean-middleware:
	-$(RM) ./middleware/led.d ./middleware/led.o ./middleware/light_sensor.d ./middleware/light_sensor.o ./middleware/queue.d ./middleware/queue.o

.PHONY: clean-middleware

