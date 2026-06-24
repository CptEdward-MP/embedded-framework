#include "robot_demo.h"

void RobotDemo_Init(
    robot_demo_t *robot)
{
    robot->yaw = 0.0f;

    robot->left_encoder = 0;
    robot->right_encoder = 0;

    robot->left_motor = 0.0f;
    robot->right_motor = 0.0f;

    LipoBattery_Configure(
        &robot->battery,
        3,
        0);

    LipoBattery_Init(
        &robot->battery);
}