set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(uptime_lib "")

target_include_directories(
    uptime_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    uptime_lib 
    PRIVATE
        uptime.cpp
        uptime_monitor.cpp
        ${INCLUDE_PATH}/system/component/uptime/uptime.h
        ${INCLUDE_PATH}/system/component/uptime/uptime_monitor.h)