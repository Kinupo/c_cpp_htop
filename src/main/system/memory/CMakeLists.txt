set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(memory_lib "")

target_include_directories(
    memory_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    memory_lib 
    PRIVATE
        memory_monitor.cpp
        memory_status.cpp
        ${INCLUDE_PATH}/system/memory/memory_monitor.h
        ${INCLUDE_PATH}/system/memory/memory_status.h)