#ifndef MOTOR_SIM_H
#define MOTOR_SIM_H

void MotorSim_Init(void);

void MotorSim_SetLeft(
    float speed);

void MotorSim_SetRight(
    float speed);

float MotorSim_GetLeft(void);

float MotorSim_GetRight(void);

#endif