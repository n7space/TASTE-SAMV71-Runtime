project(appXdmac VERSION 1.0.0 LANGUAGES C)

add_executable(appXdmac)
target_sources(appXdmac
    PRIVATE     main.c)
target_include_directories(appXdmac
    PRIVATE     ..
                ../hwas/dataview)
target_link_libraries(appXdmac
    PRIVATE     SAMV71::Startup
                SAMV71::Runtime::Init
                SAMV71::Runtime::Hal
                SAMV71::Runtime::Xdmad
                SAMV71::FreeRTOS)
target_link_options(appXdmac
    PRIVATE     -T${CMAKE_SOURCE_DIR}/SAMV71-BSP/ld/samv71q21_sram.ld)

add_format_target(appXdmac)
