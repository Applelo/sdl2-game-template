if(DEFINED ENV{VITASDK})
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
else()
  message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
endif()

# prevent to find mac os lib
set(CMAKE_FIND_USE_CMAKE_SYSTEM_PATH false)
# Add path to find libs
set(CMAKE_INCLUDE_PATH "$ENV{VITASDK}/arm-vita-eabi/include" "$ENV{VITASDK}/arm-vita-eabi/include/SDL2")
set(CMAKE_LIBRARY_PATH "$ENV{VITASDK}/arm-vita-eabi/lib")