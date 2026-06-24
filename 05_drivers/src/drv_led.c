#include "drv_led.h"
#include "board_device.h"
#include "led_base.h"   // led_on/led_off 内联函数

void drv_alarm_led_on(void) 
{
    led_on(BOARD_DEVICE(DEV_ID_ALARM_LED));
}
void drv_alarm_led_off(void) 
{
    led_off(BOARD_DEVICE(DEV_ID_ALARM_LED));
}