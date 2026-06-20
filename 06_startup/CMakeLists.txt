add_library(startup OBJECT startup_stm32f10x_md.s)
target_compile_options(startup PRIVATE -mcpu=cortex-m3 -mthumb)