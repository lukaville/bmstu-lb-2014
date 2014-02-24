#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

class Triangle
{
public:
    Triangle();

    Triangle(Point p1, Point p2, Point p3);

    Point getP1() const;
    void setP1(const Point &value);

    Point getP2() const;
    void setP2(const Point &value);

    Point getP3() const;
    void setP3(const Point &value);

private:
    Point p1, p2, p3;
};

#endif // TRIANGLE_H
