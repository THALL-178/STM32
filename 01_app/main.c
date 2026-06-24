#include "board_device.h"
#include "drv_led.h"
#include "board_init.h"

int main(void) {
    board_init();


    drv_alarm_led_on();   // 点亮报警灯

    while (1);
}