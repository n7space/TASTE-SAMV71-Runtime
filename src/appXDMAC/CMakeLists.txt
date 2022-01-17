project(appXDMAC VERSION 1.0.0 LANGUAGES C)

add_executable(appXDMAC)
target_sources(appXDMAC
    PRIVATE     main.c)
target_include_directories(appXDMAC
    PRIVATE     ..)
target_link_libraries(appXDMAC
    PRIVATE     SAMV71::Startup
                SAMV71::Runtime::Init
                SAMV71::Runtime::Xdmad
                SAMV71::Uart
                SAMV71::FreeRTOS
                SAMV71::Runtime::Hal)
target_link_options(appXDMAC
    PRIVATE     -T${CMAKE_SOURCE_DIR}/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(appXDMAC)
