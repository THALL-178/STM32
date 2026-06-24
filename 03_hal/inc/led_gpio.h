#ifndef __LED_GPIO_H
#define __LED_GPIO_H
#include "device.h"
#include "hal_types.h"

// 不透明类型声明
typedef struct led_gpio_dev led_gpio_dev_t;

// 初始化指定 id 的 LED 设备，返回统一设备指针
device_t* led_gpio_init(int id, const char *name, Hal_PortHandle port, Hal_Pin pin);

#endif