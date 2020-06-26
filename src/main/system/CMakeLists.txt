set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(systemMonitorLib "")

target_include_directories(
    systemMonitorLib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    systemMonitorLib 
    PRIVATE
        monitor_factory.cpp
        ${INCLUDE_PATH}/system/monitor_factory.h
        )

add_subdirectory(status)
add_subdirectory(operating_system)
add_subdirectory(cpu)
add_subdirectory(memory)