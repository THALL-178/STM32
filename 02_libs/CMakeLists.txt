# 收集标准外设库源文件（路径相对于02_libs目录）
file(GLOB_RECURSE STD_PERIPH_SRCS 
    "STM32F10x_StdPeriph_Driver/src/*.c"
)
list(APPEND STD_PERIPH_SRCS "CMSIS/system_stm32f10x.c")

# 创建静态库
add_library(stdperiph STATIC ${STD_PERIPH_SRCS})

# 头文件路径
target_include_directories(stdperiph PUBLIC 
    "STM32F10x_StdPeriph_Driver/inc"
    "CMSIS"
    "${CMAKE_SOURCE_DIR}/09_config"
)

# 编译选项
target_compile_options(stdperiph PRIVATE 
    -mcpu=cortex-m3 
    -mthumb
)

# 宏定义
target_compile_definitions(stdperiph PUBLIC 
    STM32F10X_MD 
    USE_STDPERIPH_DRIVER
)