project(FreeRTOSApp VERSION 1.0.0 LANGUAGES C)

add_executable(FreeRTOSApp)
target_sources(FreeRTOSApp
    PRIVATE     main.c)
target_include_directories(FreeRTOSApp
    PRIVATE     ${SAMV71_BSP_DIR}/src
                ..)
target_link_libraries(FreeRTOSApp
    PRIVATE     SAMV71::Startup
                Samv71FreeRtos::Init
                SAMV71::Uart
                SAMV71::FreeRTOS)

add_format_target(FreeRTOSApp)
