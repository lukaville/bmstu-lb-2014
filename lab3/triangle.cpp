#include "triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Point Triangle::getP1() const
{
    return p1;
}

void Triangle::setP1(const Point &value)
{
    p1 = value;
}
Point Triangle::getP2() const
{
    return p2;
}

void Triangle::setP2(const Point &value)
{
    p2 = value;
}
Point Triangle::getP3() const
{
    return p3;
}

void Triangle::setP3(const Point &value)
{
    p3 = value;
}



