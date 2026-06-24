#include "imu_sim.h"

static float yaw;

void IMUSim_Init(void)
{
    yaw = 0.0f;
}

void IMUSim_Update(void)
{
    yaw += 1.0f;

    if (yaw >= 360.0f)
    {
        yaw = 0.0f;
    }
}

float IMUSim_GetYaw(void)
{
    return yaw;
}