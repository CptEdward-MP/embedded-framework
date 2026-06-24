#ifndef ENCODER_SIM_H
#define ENCODER_SIM_H

#include <stdint.h>

void EncoderSim_Init(void);

void EncoderSim_Update(void);

int32_t EncoderSim_GetLeft(void);

int32_t EncoderSim_GetRight(void);

#endif