#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "cpoint.h"
#include <iostream>

class Rectangle
{
private:
    CPoint<int> p1;
    CPoint<int> p2;
public:
    Rectangle();
    friend std::ostream &operator<<(std::ostream &output, Rectangle &rect);
    friend std::istream &operator>>(std::istream &input, Rectangle &rect);
};

#endif // RECTANGLE_H
