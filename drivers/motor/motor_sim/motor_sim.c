#include "motor_sim.h"

static float left_speed;
static float right_speed;

void MotorSim_Init(void)
{
    left_speed = 0.0f;
    right_speed = 0.0f;
}

void MotorSim_SetLeft(
    float speed)
{
    left_speed = speed;
}

void MotorSim_SetRight(
    float speed)
{
    right_speed = speed;
}

float MotorSim_GetLeft(void)
{
    return left_speed;
}

float MotorSim_GetRight(void)
{
    return right_speed;
}