project(FreeRTOS VERSION 1.0.0 LANGUAGES C)

set(FREERTOS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../FreeRTOS-Kernel)

add_library(Samv71FreeRtos STATIC)
target_sources(Samv71FreeRtos
    PRIVATE     ${FREERTOS_DIR}/event_groups.c
                ${FREERTOS_DIR}/list.c
                ${FREERTOS_DIR}/queue.c
                ${FREERTOS_DIR}/tasks.c
                ${FREERTOS_DIR}/timers.c
                ${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1/port.c
                ${FREERTOS_DIR}/portable/MemMang/heap_4.c)
target_include_directories(Samv71FreeRtos
    PUBLIC      .
                ${FREERTOS_DIR}/include
                ${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1)
target_compile_definitions(Samv71FreeRtos
    PUBLIC      __SAMV71Q21__
                configAPPLICATION_ALLOCATED_HEAP=1)

add_library(SAMV71::FreeRTOS ALIAS Samv71FreeRtos)
