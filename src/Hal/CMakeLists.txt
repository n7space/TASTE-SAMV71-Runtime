project(Samv71RuntimeHal VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeHal STATIC)
target_sources(Samv71RuntimeHal
    PRIVATE     Hal.c
    PUBLIC      Hal.h)
target_include_directories(Samv71RuntimeHal
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Samv71RuntimeHal
    PRIVATE     SAMV71::Startup
                SAMV71::Nvic
                SAMV71::Pio
                SAMV71::Pmc
                SAMV71::Utils
                SAMV71::FreeRTOS
                SAMV71::Runtime::Xdmad
    PUBLIC      SAMV71::Uart)

add_format_target(Samv71RuntimeHal)

set_target_properties(Samv71RuntimeHal PROPERTIES OUTPUT_NAME "hal")
add_library(SAMV71::Runtime::Hal ALIAS Samv71RuntimeHal)
