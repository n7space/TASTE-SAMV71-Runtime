project(FreeRTOS VERSION 1.0.0 LANGUAGES C)

set(FREERTOS_DIR ${CMAKE_SOURCE_DIR}/FreeRTOS-Kernel)
set(LIBBOARD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libboard_samv7-ek)
set(LIBCHIP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libchip_samv7)
set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Common)

add_library(Samv71FreeRtos STATIC)
target_sources(Samv71FreeRtos
    PRIVATE     ${FREERTOS_DIR}/event_groups.c
                ${FREERTOS_DIR}/list.c
                ${FREERTOS_DIR}/queue.c
                ${FREERTOS_DIR}/tasks.c
                ${FREERTOS_DIR}/timers.c
                ${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1/port.c
                ${FREERTOS_DIR}/portable/MemMang/heap_4.c
                ${LIBBOARD_DIR}/resources/gcc/startup_sam.c
                ${LIBBOARD_DIR}/resources/system_sam.c
                ${LIBBOARD_DIR}/source/board_lowlevel.c
                ${LIBBOARD_DIR}/source/board_memories.c
                ${LIBBOARD_DIR}/source/dbg_console.c
                ${LIBBOARD_DIR}/source/led.c
                ${LIBBOARD_DIR}/source/syscalls.c
                ${LIBCHIP_DIR}/source/mpu.c
                ${LIBCHIP_DIR}/source/pio.c
                ${LIBCHIP_DIR}/source/pmc.c
                ${LIBCHIP_DIR}/source/supc.c
                ${LIBCHIP_DIR}/source/tc.c
                ${LIBCHIP_DIR}/source/wdt.c)
target_include_directories(Samv71FreeRtos
    PUBLIC      .
                ${LIBBOARD_DIR}
                ${LIBCHIP_DIR}
                ${LIBCHIP_DIR}/include/samv7
                ${LIBCHIP_DIR}/include/cmsis/CMSIS/Include
                ${FREERTOS_DIR}/include
                ${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1
                ${COMMON_DIR}/include)
target_compile_definitions(Samv71FreeRtos
    PUBLIC      __SAMV71Q21__)

add_library(SAMV71::FreeRTOS ALIAS Samv71FreeRtos)
