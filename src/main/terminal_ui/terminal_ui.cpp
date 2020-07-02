#include "terminal_ui/terminal_ui.h"
#include "terminal_ui/view/dimension.h"

void TerminalUi::InitilizeTerminal(){
  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color
  curs_set(0);    // hide cursor
}

int TerminalUi::ComputeWindowHeight(const int height, const int starting_y){
    return height < 1 ? getmaxy(stdscr) - starting_y +1 : height;//+1 because max y is 0 indexed
}

void TerminalUi::DrawWindows(std::map<std::string, WINDOW*> windows){
    for(auto window : windows){
      wnoutrefresh(window.second);
    }
    doupdate();
}

WINDOW* TerminalUi::CreateWindow(const int height, const int width, const int y_position, const int x_position){
    return newwin(
        ComputeWindowHeight(height, y_position) -1, //-1: 0 index adjustment
        width > 1 ? width -1 : getmaxx(stdscr) -1, //-1: 0 index adjustment
        y_position, 
        x_position);
}

WINDOW* TerminalUi::CreateWindow(const Dimension dimension){
    return CreateWindow(dimension.Height(), dimension.Width(), 0, 0);
}

WINDOW* TerminalUi::CreateWindow(const int height, const int width){
    return CreateWindow(height, width, 0, 0);
}

WINDOW* TerminalUi::CreateWindowBelow(WINDOW* relitive_window, const int height, const int width){
   return CreateWindow(
        height, 
        width, 
        nullptr == relitive_window ? 0 : relitive_window->_maxy +1, //+1 for 1 line of buffer
        nullptr == relitive_window ? 0 : relitive_window->_begx);
}