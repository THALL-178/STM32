#ifndef __DRV_LED_H
#define __DRV_LED_H

#include <stdint.h>

void drv_alarm_led_on(void);
void drv_alarm_led_off(void);
void drv_alarm_led_flash(uint8_t count);

void drv_status_led_on(void);
void drv_status_led_off(void);

#endif