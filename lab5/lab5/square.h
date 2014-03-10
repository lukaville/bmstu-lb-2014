#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square();

    friend const Square operator++(Square& i, int) {
        Square oldValue = i;
        i.p1.setX(i.p1.getX() + 32);
        i.p1.setY(i.p1.getY() + 32);
        i.p2.setX(i.p2.getX() + 32);
        i.p2.setY(i.p2.getY() + 32);
        return oldValue;
    }
};

#endif // SQUARE_H
