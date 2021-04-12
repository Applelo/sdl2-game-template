cmake_minimum_required(VERSION 3.7)
project(SDL2Test)

if (VITA)
    include("${VITASDK}/share/vita.cmake" REQUIRED)
    add_definitions(-DVITA)
elseif(PSP)
    add_definitions(-DPSP)
else()
    add_definitions(-DMAC)
endif()

set(SRC_DIR src)
set(SOURCES
    ${SRC_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/find")

find_package(TMXLITE REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
    ${TMXLITE_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    ${TMXLITE_LIBRARIES}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
)
