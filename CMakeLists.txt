cmake_minimum_required(VERSION 3.0)
project(SDL2Test)

set(MAC false)
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
    ${SCE_LIBRARY}
)

if(VITA)
    vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
    vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
    VERSION ${VITA_VERSION}
    NAME ${VITA_APP_NAME}
    FILE platforms/psvita/sce_sys/icon0.png sce_sys/icon0.png
    FILE platforms/psvita/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
    FILE platforms/psvita/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
    FILE platforms/psvita/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
    )
endif(VITA)
