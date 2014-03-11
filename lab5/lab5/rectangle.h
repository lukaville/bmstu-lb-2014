#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "cpoint.h"
#include <iostream>
#include <vector>

class Rectangle
{
protected:
    CPoint<int> p1;
    CPoint<int> p2;
    std::vector<CPoint<int>> points;
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

    // Plus and minus
    friend const Rectangle operator+(const Rectangle& left, const Rectangle& right);

    friend const Rectangle operator-(const Rectangle& left, const Rectangle& right) {
        Rectangle r;
        r.p1.setX(left.p1.getX() - right.p1.getX());
        r.p1.setY(left.p1.getY() - right.p1.getY());
        r.p2.setX(left.p2.getX() - right.p2.getX());
        r.p2.setY(left.p2.getY() - right.p2.getY());
        return r;
    }

    // [] operator overloading
    CPoint<int>& operator [] (unsigned i) {
        return points.at(i);
    }

    Rectangle& operator=(const Rectangle& r)
    {
      this->p1 = r.p1;
      this->p2 = r.p2;
      return *this;
    }
};

#endif // RECTANGLE_H
