#ifndef __BOARD_DEVICE_H
#define __BOARD_DEVICE_H

// 外部声明设备表
#include "device.h"

// 设备索引枚举
typedef enum 
{
    DEV_ID_ALARM_LED = 0,
    DEV_ID_STATUS_LED,
    // 以后扩展：DEV_ID_DEBUG_UART, 等等
    DEV_ID_MAX
} board_device_id_t;

// 获取设备指针的宏（直接从静态表中拿）
#define BOARD_DEVICE(id)  (board_device_table[id])


extern device_t *board_device_table[DEV_ID_MAX];

// ====== LED 设备配置表（新增 LED 只需加一行） ======
#define BOARD_LED_TABLE \
    LED_ENTRY(DEV_ID_ALARM_LED,  GPIOA, GPIO_Pin_5,  "alarm_led") \
    LED_ENTRY(DEV_ID_STATUS_LED, GPIOA, GPIO_Pin_4, "status_led")

#endif                     