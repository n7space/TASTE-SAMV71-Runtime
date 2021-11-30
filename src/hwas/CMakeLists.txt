project(Samv71RuntimeHwas VERSION 1.0.0 LANGUAGES C)

add_library(Samv71RuntimeHwas STATIC)
target_sources(Samv71RuntimeHwas
    PRIVATE     hwas.c
    PUBLIC      hwas.h)
target_include_directories(Samv71RuntimeHwas
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/..
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/dataview)
target_link_libraries(Samv71RuntimeHwas
    PRIVATE     SAMV71::Nvic)

add_format_target(Samv71RuntimeHwas)                

set_target_properties(Samv71RuntimeHwas PROPERTIES OUTPUT_NAME "hwas")
add_library(SAMV71::Runtime::Hwas ALIAS Samv71RuntimeHwas)
