#include "led_gpio.h"
#include "board_device.h"
#include "hal_gpio.h"
#include "stm32f10x.h"
#include <stddef.h>
#include "led_base.h"  
#define MAX_LED_DEVICES 8

typedef struct {
    Hal_PortHandle port;
    Hal_Pin pin;
} led_gpio_config_t;

typedef struct {
    uint8_t state;
} led_gpio_data_t;

struct led_gpio_dev {
    device_t dev;
    led_gpio_config_t cfg;
    led_gpio_data_t  data;
};

static led_gpio_dev_t led_devices[MAX_LED_DEVICES];

static void on(device_t *dev) {
    led_gpio_dev_t *self = (led_gpio_dev_t*)dev;
    hal_gpio_write(self->cfg.port, self->cfg.pin, 0);
}
static void off(device_t *dev) {
    led_gpio_dev_t *self = (led_gpio_dev_t*)dev;
    hal_gpio_write(self->cfg.port, self->cfg.pin, 1);
}

static const struct led_ops gpio_ops = {
    .on = on,
    .off = off,
    .set_brightness = NULL
};




device_t* led_gpio_init(int id, const char *name, Hal_PortHandle port, Hal_Pin pin) {
    if (id < 0 || id >= MAX_LED_DEVICES) return NULL;
    led_gpio_dev_t *dev = &led_devices[id];
    dev->dev.name   = name;
    dev->dev.config = &dev->cfg;
    dev->dev.data   = &dev->data;
    dev->dev.ops    = (const struct device_ops*)&gpio_ops;
    dev->cfg.port = port;
    dev->cfg.pin  = pin;
    hal_gpio_init(port, pin, HAL_GPIO_MODE_OUTPUT_PP);
    hal_gpio_write(port, pin, 1);
    return &dev->dev;
}

/* ---------- 自动注册 ---------- */
static device_t* alarm_led_init_wrapper(void) {
    device_t *dev = led_gpio_init(0, "alarm_led", GPIOA, GPIO_Pin_5);
    board_device_table[DEV_ID_ALARM_LED] = dev;
    return dev;
}
DEVICE_REGISTER(alarm_led_init_wrapper, "alarm_led");

static device_t* status_led_init_wrapper(void) {
    device_t *dev = led_gpio_init(1, "status_led", GPIOA, GPIO_Pin_4);
    board_device_table[DEV_ID_STATUS_LED] = dev;
    return dev;
}
DEVICE_REGISTER(status_led_init_wrapper, "status_led");