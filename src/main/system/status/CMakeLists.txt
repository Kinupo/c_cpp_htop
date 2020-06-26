set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(status_monitor_lib "")

target_include_directories(
    status_monitor_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    status_monitor_lib 
    PRIVATE
        system_monitor.cpp
        system_status.cpp
        ${INCLUDE_PATH}/system/status/system_monitor.h
        ${INCLUDE_PATH}/system/status/system_status.h
        )