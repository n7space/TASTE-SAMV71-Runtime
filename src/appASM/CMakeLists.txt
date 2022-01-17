project(appASM VERSION 1.0.0 LANGUAGES C)

add_executable(appASM)
target_sources(appASM
    PRIVATE     main.c)
target_include_directories(appASM
    PRIVATE     ..)
target_link_libraries(appASM
    PRIVATE     SAMV71::Startup
                SAMV71::Runtime::Init
                SAMV71::Uart
                SAMV71::FreeRTOS
                SAMV71::Runtime::Hal)
target_link_options(appASM
    PRIVATE     -T${CMAKE_SOURCE_DIR}/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(appASM)
