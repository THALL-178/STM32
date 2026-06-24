#ifndef __DEVICE_H
#define __DEVICE_H
#include <stdint.h>

struct device;
struct device_pm_ops;
struct device_ops;

typedef struct device {
    const char *name;
    const void *config;
    void *data;
    const struct device_ops *ops;
    const struct device_pm_ops *pm;
} device_t;



// 初始化函数类型
typedef device_t* (*device_init_fn)(void);

// 注册条目
typedef struct {
    device_init_fn init;
    const char *name;
} device_reg_entry_t;

#define DEVICE_REG_SECTION ".device_reg"

// 注册宏
#define DEVICE_REGISTER(init_fn, name_str) \
    const device_reg_entry_t \
    __attribute__((used, section(DEVICE_REG_SECTION))) \
    __device_reg_##init_fn = { init_fn, name_str }

// 符号声明为 char 数组
extern char __device_reg_start[];
extern char __device_reg_end[];

#endif