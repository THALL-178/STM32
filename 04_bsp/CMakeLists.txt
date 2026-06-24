file(GLOB BSP_SRCS "src/*.c")
add_library(bsp OBJECT ${BSP_SRCS})          # 改成 OBJECT
target_include_directories(bsp PUBLIC inc)
target_link_libraries(bsp PUBLIC stdperiph board_config hal)