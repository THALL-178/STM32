# 创建接口库：不编译任何源文件，只传递头文件路径和依赖
add_library(hal INTERFACE)

# 让使用 hal 的目标自动找到 03_hal/inc 下的头文件
target_include_directories(hal INTERFACE inc)

# HAL 的依赖关系（接口库也用 INTERFACE 传递）
target_link_libraries(hal INTERFACE bsp board_config)