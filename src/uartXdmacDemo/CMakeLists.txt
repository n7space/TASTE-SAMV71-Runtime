project(uartXdmacDemo VERSION 1.0.0 LANGUAGES C)

add_executable(uartXdmacDemo)
target_sources(uartXdmacDemo
    PRIVATE     main.c)
target_include_directories(uartXdmacDemo
    PRIVATE     ..)
target_link_libraries(uartXdmacDemo
    PRIVATE     SAMV71::Startup
                SAMV71::Runtime::Init
                SAMV71::Runtime::Xdmad
                SAMV71::FreeRTOS
                SAMV71::Runtime::Hal)
target_link_options(uartXdmacDemo
    PRIVATE     -T${CMAKE_SOURCE_DIR}/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(uartXdmacDemo)
