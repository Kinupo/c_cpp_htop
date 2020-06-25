set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

target_include_directories(
    monitor 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    monitor 
    PRIVATE
        main.cpp
#       ${INCLUDE_PATH}/system/display/ncurses_display.h
        )

#add_subdirectory(display)
#add_subdirectory(file)
#add_subdirectory(system)

find_library(CURSES_LIBRARIES curses)
target_link_libraries(monitor ${CURSES_LIBRARIES})