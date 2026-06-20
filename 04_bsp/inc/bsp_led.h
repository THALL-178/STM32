#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED_PIN GPIO_Pin_6
#define LED_PORT GPIOA

void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif /* __BSP_LED_H */