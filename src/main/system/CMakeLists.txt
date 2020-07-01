set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(system_monitor_lib "")

target_include_directories(
    system_monitor_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    system_monitor_lib 
    PRIVATE
        monitor_factory.cpp
        ${INCLUDE_PATH}/system/monitor_factory.h
        )


add_subdirectory(status)
add_subdirectory(user)
add_subdirectory(component)

target_link_libraries(
    system_monitor_lib 
        component_lib
        status_monitor_lib
        operating_system_lib
        cpu_lib
        memory_lib
        uptime_lib
        user_lib
        processes_monitor_lib
)