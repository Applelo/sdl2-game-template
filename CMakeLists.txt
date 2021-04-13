cmake_minimum_required(VERSION 3.0)
project(SDL2Test)

if (VITA)
    include("${VITASDK}/share/vita.cmake" REQUIRED)

    # Add path to find libs
    set(SDL2_PATH "$ENV{VITASDK}/arm-vita-eabi/include/SDL2")

    #Vita info
    set(VITA_APP_NAME "Red Rectangle")
    set(VITA_TITLEID  "VSDK00017")
    set(VITA_VERSION  "01.00")
    set(VITA_IP "$ENV{VITA_IP}")
    set(VITA3K_PATH "$ENV{VITA3K_PATH}")

    #SCE LIBRARY
    set(SCE_LIBRARY
        SDL2
        SceDisplay_stub
        SceCtrl_stub
        SceAudio_stub
        SceSysmodule_stub
        SceGxm_stub
        SceCommonDialog_stub
        SceAppMgr_stub
        SceTouch_stub
        SceHid_stub
        SceMotion_stub
        m
    )
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
    vita_create_self(eboot.bin ${PROJECT_NAME})
    vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} eboot.bin
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FILE platforms/psvita/sce_sys/icon0.png sce_sys/icon0.png
        FILE platforms/psvita/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
        FILE platforms/psvita/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        FILE platforms/psvita/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
    )

    add_custom_target(send
        COMMAND curl -T eboot.bin ftp://${VITA_IP}:1337/ux0:/app/${VITA_TITLEID}/
        #COMMAND socat udp-recv:18194 stdout
        DEPENDS eboot.bin
    )

    add_custom_target(copy
        COMMAND cp eboot.bin F:/app/${VITA_TITLEID}/eboot.bin
        DEPENDS eboot.bin
    )

    add_custom_target(send_vpk
        COMMAND curl -T ${PROJECT_NAME}.vpk ftp://${VITA_IP}:1337/ux0:/data/
        DEPENDS ${PROJECT_NAME}.vpk
    )

    add_custom_target(copy_vpk
        COMMAND cp ${PROJECT_NAME}.vpk F:/data/${VITA_TITLEID}/${PROJECT_NAME}.vpk
        DEPENDS ${PROJECT_NAME}.vpk
    )

    add_custom_target(emulator
        COMMAND ${VITA3K_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.vpk
        DEPENDS ${PROJECT_NAME}.vpk
    )
endif(VITA)
