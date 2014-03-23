################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Person.cpp \
../Population.cpp \
../Simulation.cpp \
../main.cpp \
../statistics_helpers.cpp 

OBJS += \
./Person.o \
./Population.o \
./Simulation.o \
./main.o \
./statistics_helpers.o 

CPP_DEPS += \
./Person.d \
./Population.d \
./Simulation.d \
./main.d \
./statistics_helpers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


