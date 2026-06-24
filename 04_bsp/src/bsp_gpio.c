#include "hal_gpio.h"
#include "stm32f10x.h"        // 芯片头文件，只在此处出现

// 模式映射
static GPIOMode_TypeDef map_mode(Hal_GpioMode mode) 
{
    switch(mode) 
    {
        case HAL_GPIO_MODE_OUTPUT_PP: return GPIO_Mode_Out_PP;
        case HAL_GPIO_MODE_OUTPUT_OD: return GPIO_Mode_Out_OD;
        case HAL_GPIO_MODE_INPUT_FLOATING: return GPIO_Mode_IN_FLOATING;
        case HAL_GPIO_MODE_INPUT_PULLUP: return GPIO_Mode_IPU;
        default: return GPIO_Mode_Out_PP;
    }
}

void hal_gpio_init(Hal_PortHandle port, Hal_Pin pin, Hal_GpioMode mode) 
{
    GPIO_TypeDef* gpio = (GPIO_TypeDef*)port;   // 强制还原芯片类型

    switch((uint32_t)gpio) 
    {
        case (uint32_t)GPIOA: RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; break;
        case (uint32_t)GPIOB: RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; break;
        case (uint32_t)GPIOC: RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; break;
        case (uint32_t)GPIOD: RCC->APB2ENR |= RCC_APB2ENR_IOPDEN; break;
        case (uint32_t)GPIOE: RCC->APB2ENR |= RCC_APB2ENR_IOPEEN; break;
    }

    GPIO_InitTypeDef gpio_initstruct;
    gpio_initstruct.GPIO_Pin = pin;
    gpio_initstruct.GPIO_Mode = map_mode(mode);
    gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(gpio, &gpio_initstruct);
}

void hal_gpio_write(Hal_PortHandle port, Hal_Pin pin, uint8_t level) 
{
    GPIO_TypeDef* gpio = (GPIO_TypeDef*)port;
    if(level)
    {
        GPIO_SetBits(gpio, pin);
    }
    else
    {
        GPIO_ResetBits(gpio, pin);
    }
}

void hal_gpio_toggle(Hal_PortHandle port, Hal_Pin pin) 
{
    GPIO_TypeDef* gpio = (GPIO_TypeDef*)port;

    if(gpio->ODR & pin)
    {
        GPIO_ResetBits(gpio, pin);
    }
    else
    {
        GPIO_SetBits(gpio, pin);
    }
}