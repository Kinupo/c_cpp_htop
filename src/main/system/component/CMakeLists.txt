set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(component_lib INTERFACE)

target_include_directories(
    component_lib 
    INTERFACE
        ${INCLUDE_PATH})

target_sources(
    component_lib 
    INTERFACE
        ${INCLUDE_PATH}/system/component/component_type.h
        ${INCLUDE_PATH}/system/component/component_status.h
        ${INCLUDE_PATH}/system/component/component_monitor.h)

add_subdirectory(process)
add_subdirectory(operating_system)
add_subdirectory(cpu)
add_subdirectory(memory)
add_subdirectory(uptime)