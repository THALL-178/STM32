cmake_minimum_required(VERSION 3.20)
project(STM32F103C8T6 C ASM)

# 不再添加 add_compile_options，交由工具链文件全权负责

add_subdirectory(02_libs)
add_subdirectory(06_startup)
add_subdirectory(09_config)
add_subdirectory(04_bsp)
add_subdirectory(03_hal)
add_subdirectory(05_drivers)
add_subdirectory(01_app)