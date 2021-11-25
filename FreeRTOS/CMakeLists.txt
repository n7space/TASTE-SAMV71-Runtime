project(FreeRTOS VERSION 1.0.0 LANGUAGES C)

add_library(Samv71FreeRtos STATIC)
target_sources(Samv71FreeRtos
    PRIVATE     FreeRTOS-Kernel/event_groups.c
                FreeRTOS-Kernel/list.c
                FreeRTOS-Kernel/queue.c
                FreeRTOS-Kernel/tasks.c
                FreeRTOS-Kernel/timers.c
                FreeRTOS-Kernel/portable/GCC/ARM_CM7/r0p1/port.c
                FreeRTOS-Kernel/portable/MemMang/heap_4.c)
target_include_directories(Samv71FreeRtos
    PUBLIC      .
                FreeRTOS-Kernel/include
                FreeRTOS-Kernel/portable/GCC/ARM_CM7/r0p1)
target_compile_definitions(Samv71FreeRtos
    PUBLIC      __SAMV71Q21__
                configAPPLICATION_ALLOCATED_HEAP=1)

add_library(SAMV71::FreeRTOS ALIAS Samv71FreeRtos)
