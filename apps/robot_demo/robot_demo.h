#ifndef ROBOT_DEMO_H
#define ROBOT_DEMO_H

#include "lipo_battery.h"

typedef struct
{
    float yaw;

    int left_encoder;

    int right_encoder;

    float left_motor;

    float right_motor;

    lipo_battery_t battery;

} robot_demo_t;

void RobotDemo_Init(
    robot_demo_t *robot);

#endif