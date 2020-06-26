#ifndef TERMINAL_UI
#define TERMINAL_UI

#include <curses.h>

#include <map>

class TerminalUi {
    private:
        int ComputeWindowHeight(const int height, const int starting_y);
        WINDOW* CreateWindow(const int height, const int width, const int x_position, const int y_postion);
    public:
        void InitilizeTerminal();
        void DrawWindows(std::map<std::string, WINDOW*> windows);
        //less than 1 width is adjusted to max
        //less than 1 height is adjusted to max
        WINDOW* CreateWindow(const int height, const int width);
        //less than 1 width is adjusted to max
        //less than 1 height is adjusted to max to the botom of the screen from the bottom of the relitive window
        WINDOW* CreateWindowBelow(WINDOW* relitive_window, const int height, const int width);
};

#endif