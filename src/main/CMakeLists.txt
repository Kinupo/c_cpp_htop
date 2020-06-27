set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)
set(THREADS_PREFER_PTHREAD_FLAG ON)

target_include_directories(
    monitor 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    monitor 
    PRIVATE
        main.cpp
        ${INCLUDE_PATH}/system/monitor_factory.h
        ${INCLUDE_PATH}/system/status/system_monitor.h
        ${INCLUDE_PATH}/terminal_ui/terminal_ui.h
#       ${INCLUDE_PATH}/system/display/ncurses_display.h
        )

#add_subdirectory(display)
#add_subdirectory(file)
add_subdirectory(system)
add_subdirectory(terminal_ui)

find_library(CURSES_LIBRARIES curses)
find_package(Threads REQUIRED)
target_link_libraries(
    monitor 
        ${CURSES_LIBRARIES}
        Threads::Threads
        systemMonitorLib
        status_monitor_lib
        operating_system_lib
        cpu_lib
        memory_lib
        terminal_lib
        uptime_lib
        user_lib
)