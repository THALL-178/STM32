#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#include "hal_types.h"


// 抽象模式枚举（与芯片无关）
typedef enum 
{
    HAL_GPIO_MODE_OUTPUT_PP,
    HAL_GPIO_MODE_OUTPUT_OD,
    HAL_GPIO_MODE_INPUT_FLOATING,
    HAL_GPIO_MODE_INPUT_PULLUP
} Hal_GpioMode;



void hal_gpio_init(Hal_PortHandle port, Hal_Pin pin, Hal_GpioMode mode);
void hal_gpio_write(Hal_PortHandle port, Hal_Pin pin, uint8_t level);
void hal_gpio_toggle(Hal_PortHandle port, Hal_Pin pin);



#endif /* __HAL_GPIO_H__ */

