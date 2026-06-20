cmake_minimum_required(VERSION 3.10)

project(STM32F103C8T6 C ASM)

add_subdirectory(02_libs)

add_subdirectory(06_startup)

add_subdirectory(09_config)

add_subdirectory(04_bsp)

add_subdirectory(03_hal)

add_subdirectory(01_app)