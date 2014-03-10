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

    // Unary +
    friend const Rectangle& operator+(const Rectangle& i);

    // Unary -
    friend const Rectangle operator-(const Rectangle& i);

    // Prefix inc
    friend const Rectangle& operator++(Rectangle& i);

    // Postfix inc
    friend const Rectangle operator++(Rectangle& i, int);

    // Prefix dec
    friend const Rectangle& operator--(Rectangle& i);

    // Postfix dec
    friend const Rectangle operator--(Rectangle& i, int);
};

#endif // RECTANGLE_H
