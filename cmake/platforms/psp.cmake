#https://github.com/psp2sdk/cmake/blob/master/src/cmake/toolchain-arm-none-eabi-psp2.cmake

# Setup arch info
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-a9)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

# Set compilation flags
set(CMAKE_C_FLAGS "-mcpu=cortex-a9 -mfpu=neon-fp16" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "-mcpu=cortex-a9 -mfpu=neon-fp16" CACHE STRING "" FORCE)

# set these global flags for cmake client scripts to change behavior
set( PSP True )
set( BUILD_PSP True )
