#ifndef __LED_BASE_H
#define __LED_BASE_H
#include <stdint.h>

struct device;   // 前置声明

struct led_ops 
{
    void (*on)(struct device *dev);
    void (*off)(struct device *dev);
    void (*set_brightness)(struct device *dev, uint8_t percent);
};

// 包装函数（内联）
static inline int led_on(struct device *dev) 
{
    const struct led_ops *ops = (const struct led_ops*)dev->ops;
    if (ops && ops->on) 
    { 
        ops->on(dev); return 0; 
    }
    return -1;
}
static inline int led_off(struct device *dev) 
{
    const struct led_ops *ops = (const struct led_ops*)dev->ops;
    if (ops && ops->off)
    { 
        ops->off(dev); return 0; 
    }
    return -1;
}

#endif