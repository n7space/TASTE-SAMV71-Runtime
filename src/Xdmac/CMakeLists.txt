project(Samv71RuntimeXdmac VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeXdmac STATIC)
target_sources(Samv71RuntimeXdmac
    PRIVATE     Xdmac.c
    PUBLIC      Xdmac.h)
target_include_directories(Samv71RuntimeXdmac
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Samv71RuntimeXdmac
    PRIVATE     SAMV71::Startup)

add_format_target(Samv71RuntimeXdmac)

set_target_properties(Samv71RuntimeXdmac PROPERTIES OUTPUT_NAME "xdmac")
add_library(SAMV71::Runtime::Xdmac ALIAS Samv71RuntimeXdmac)
