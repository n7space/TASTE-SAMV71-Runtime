cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchains/samv71.cmake)
project(Samv71FreeRtos VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(MessageColors)
include(LoggingHelper)
include(ClangFormat)

add_library(common_build_options INTERFACE)
include(CommonBuildOptions)
include(Sanitizers)

add_library(bsp_build_options INTERFACE)
target_compile_definitions(bsp_build_options
    INTERFACE   USE_UART_IO
                LOW_LEVEL_IO_UART_ID=4)

add_subdirectory(SAMV71-BSP)
add_subdirectory(src)
