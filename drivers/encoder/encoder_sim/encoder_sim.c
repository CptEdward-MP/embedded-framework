#include "encoder_sim.h"

static int32_t left_count;
static int32_t right_count;

void EncoderSim_Init(void)
{
    left_count = 0;
    right_count = 0;
}

void EncoderSim_Update(void)
{
    left_count += 5;
    right_count += 5;
}

int32_t EncoderSim_GetLeft(void)
{
    return left_count;
}

int32_t EncoderSim_GetRight(void)
{
    return right_count;
}