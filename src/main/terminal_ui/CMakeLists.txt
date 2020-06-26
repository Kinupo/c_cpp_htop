set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(terminal_lib "")

target_include_directories(
    terminal_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    terminal_lib 
    PRIVATE
        terminal_ui.cpp
        ${INCLUDE_PATH}/terminal_ui/terminal_ui.h
        )

find_library(CURSES_LIBRARIES curses)
target_link_libraries(terminal_lib ${CURSES_LIBRARIES})