add_library(board_config INTERFACE)

target_include_directories(board_config INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
# 这里也可以放公共的宏
target_compile_definitions(board_config INTERFACE
    HSE_VALUE=8000000
)