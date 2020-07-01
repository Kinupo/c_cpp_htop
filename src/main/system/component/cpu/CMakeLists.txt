set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(cpu_lib "")

target_include_directories(
    cpu_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    cpu_lib 
    PRIVATE
        processors_status.cpp
        processors_monitor.cpp
        ${INCLUDE_PATH}/system/component/cpu/processors_status.h
        ${INCLUDE_PATH}/system/component/cpu/processors_monitor.h)