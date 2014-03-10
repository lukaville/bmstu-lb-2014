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

    // Prefix inc
    friend const Rectangle& operator++(Rectangle& i);

    // Postfix inc
    friend const Rectangle operator++(Rectangle& i, int) {
        Rectangle oldValue = i;
        i.p1.setX(i.p1.getX() + 1);
        i.p1.setY(i.p1.getY() + 1);
        i.p2.setX(i.p2.getX() + 1);
        i.p2.setY(i.p2.getY() + 1);
        return oldValue;
    }

    // Prefix dec
    friend const Rectangle& operator--(Rectangle& i);

    // Postfix dec
    friend const Rectangle operator--(Rectangle& i, int);
};

#endif // RECTANGLE_H
