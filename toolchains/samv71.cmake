set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

set(SAMV71_BSP_DIR ${CMAKE_SOURCE_DIR}/SAMV71-BSP)

set(CMAKE_C_FLAGS
"-mcpu=cortex-m7 \
-mfloat-abi=hard \
-mfpu=fpv5-d16 \
-mlittle-endian \
-mthumb \
-ffunction-sections")
set(CMAKE_CXX_FLAGS
"-mcpu=cortex-m7 \
-mfloat-abi=hard \
-mfpu=fpv5-d16 \
-mlittle-endian \
-mthumb \
-ffunction-sections")
set(CMAKE_EXE_LINKER_FLAGS
"-eexception_table \
-Wl,--gc-sections \
-specs=nosys.specs \
-T${SAMV71_BSP_DIR}/ld/samv71q21_sram.ld")
