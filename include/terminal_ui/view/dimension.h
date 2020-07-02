#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension{
    private:
        const int height;
        const int width;
    public:
        constexpr static int kMaxHeight = -1;
        constexpr static int kMaxWidth = -1;

        Dimension(const int height, const int width);
        int Height() const;
        int Width() const;
};

#endif