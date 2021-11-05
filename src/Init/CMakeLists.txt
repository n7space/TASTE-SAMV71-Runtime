
project(Samv71RuntimeInit VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeInit STATIC)
target_sources(Samv71RuntimeInit
    PRIVATE     Init.c
    PUBLIC      Init.h)
target_include_directories(Samv71RuntimeInit
    PRIVATE     ${SAMV71_BSP_DIR}/src)
target_link_libraries(Samv71RuntimeInit
    PRIVATE     SAMV71::Startup
                SAMV71::Fpu
                SAMV71::Nvic
                SAMV71::Pio
                SAMV71::Pmc
                SAMV71::Uart
                SAMV71::Wdt
                SAMV71::Sdramc
                SAMV71::FreeRTOS)

set_target_properties(Samv71RuntimeInit PROPERTIES OUTPUT_NAME "init")
add_library(SAMV71::Runtime::Init ALIAS Samv71RuntimeInit)
