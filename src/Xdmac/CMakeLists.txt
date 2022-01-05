project(Samv71RuntimeXdmad VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeXdmad STATIC)
target_sources(Samv71RuntimeXdmad
    PRIVATE     xdma_hardware_interface.c
                xdmad.c
    PUBLIC      xdmad.h
                xdma_hardware_interface.h)
target_include_directories(Samv71RuntimeXdmad
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Samv71RuntimeXdmad
    PRIVATE     SAMV71::Startup)

add_format_target(Samv71RuntimeXdmad)

set_target_properties(Samv71RuntimeXdmad PROPERTIES OUTPUT_NAME "xdmad")
add_library(SAMV71::Runtime::Xdmad ALIAS Samv71RuntimeXdmad)
