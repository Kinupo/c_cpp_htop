set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(operating_system_lib "")

target_include_directories(
    operating_system_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    operating_system_lib 
    PRIVATE
        operating_system_status.cpp
        operating_system_monitor.cpp
        ${INCLUDE_PATH}/system/component/operating_system/operating_system_status.h
        ${INCLUDE_PATH}/system/component/operating_system/operating_system_monitor.h)