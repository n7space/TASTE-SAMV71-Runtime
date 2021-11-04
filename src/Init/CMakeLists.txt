
project(Samv71FreeRtos VERSION 1.0.0 LANGUAGES C)

add_library(Samv71FreeRtosInit STATIC)
target_sources(Samv71FreeRtosInit
    PRIVATE     Init.c
    PUBLIC      Init.h)
target_include_directories(Samv71FreeRtosInit
    PRIVATE     ${SAMV71_BSP_DIR}/src)
target_link_libraries(Samv71FreeRtosInit
    PRIVATE     SAMV71::Startup
                SAMV71::Fpu
                SAMV71::Nvic
                SAMV71::Pio
                SAMV71::Pmc
                SAMV71::Uart
                SAMV71::Wdt
                SAMV71::Sdramc
                SAMV71::FreeRTOS)

set_target_properties(Samv71FreeRtosInit PROPERTIES OUTPUT_NAME "init")
add_library(Samv71FreeRtos::Init ALIAS Samv71FreeRtosInit)
