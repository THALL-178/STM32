file(GLOB DRV_SRCS "src/*.c")
add_library(drivers STATIC ${DRV_SRCS})
target_include_directories(drivers PUBLIC inc)
target_link_libraries(drivers PUBLIC bsp)