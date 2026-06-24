add_library(hal INTERFACE)
target_include_directories(hal INTERFACE inc)
target_link_libraries(hal INTERFACE bsp board_config)