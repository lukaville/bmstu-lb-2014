#ifndef RECTANGLE1_H
#define RECTANGLE1_H

#include "cpoint.h"
#include <iostream>

class Rectangle1
{
private:
    CPoint<int> p1;
    CPoint<int> p2;
public:
    Rectangle1();
    friend std::ostream &operator<<(std::ostream &output, Rectangle1 &rect);
    friend std::istream &operator>>(std::istream &input, Rectangle1 &rect);

    // Prefix inc
    friend const Rectangle1& operator++(Rectangle1& i);

    // Postfix inc
    friend const Rectangle1 operator++(Rectangle1& i, int) {
        Rectangle1 oldValue = i;
        i.p1.setX(i.p1.getX() + 1);
        i.p1.setY(i.p1.getY() + 1);
        i.p2.setX(i.p2.getX() + 1);
        i.p2.setY(i.p2.getY() + 1);
        return oldValue;
    }

    // Prefix dec
    friend const Rectangle1& operator--(Rectangle1& i);

    // Postfix dec
    friend const Rectangle1 operator--(Rectangle1& i, int);

    // Plus and minus
    friend const Rectangle1 operator+(const Rectangle1& left, const Rectangle1& right);

    friend const Rectangle1 operator-(const Rectangle1& left, const Rectangle1& right);

    friend const Rectangle1 operator*(const Rectangle1& left, const Rectangle1& right);
};

#endif // RECTANGLE1_H
