add_executable(STM32F103.elf main.c)
target_compile_options(STM32F103.elf PRIVATE -mcpu=cortex-m3 -mthumb)
target_link_libraries(STM32F103.elf PRIVATE
    bsp
    drivers
    startup
)

target_link_options(STM32F103.elf PRIVATE
    -mcpu=cortex-m3 -mthumb
    -T ${CMAKE_SOURCE_DIR}/09_config/linker/stm32_flash.ld
    -nostdlib
    -Wl,-Map=${CMAKE_BINARY_DIR}/STM32F103.map
)
# hex/bin 生成
add_custom_command(TARGET STM32F103.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O ihex $<TARGET_FILE:STM32F103.elf> ${CMAKE_BINARY_DIR}/STM32F103.hex
    COMMAND arm-none-eabi-objcopy -O binary $<TARGET_FILE:STM32F103.elf> ${CMAKE_BINARY_DIR}/STM32F103.bin
)
# 烧录
add_custom_target(flash
    COMMAND openocd -f interface/stlink.cfg -f target/stm32f1x.cfg
            -c "program ${CMAKE_BINARY_DIR}/STM32F103.hex verify reset exit"
    DEPENDS STM32F103.elf
)