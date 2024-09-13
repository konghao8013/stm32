#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32F10x.h"


void Systick_Init(void);
void TimingDelay_Decrement(void);

void Delay_Us(__IO uint32_t time);

void Systick_Delay(__IO uint32_t time);
void Systick_Delay_Us(__IO uint32_t time);
void Systick_Delay_Ms(__IO uint32_t time);
void Systick_Delay_S(__IO uint32_t time);
#endif
