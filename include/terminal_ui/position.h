#ifndef POSITION_H
#define POSITION_H

class Position{
    private:
        const int x;
        const int y;
    public:
        Position(const int x, const int y);
        int X();
        int Y();
};

#endif