#include "point.h"

Point::Point()
{
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Point::getX() const
{
    return x;
}

void Point::setX(double value)
{
    x = value;
}
double Point::getY() const
{
    return y;
}

void Point::setY(double value)
{
    y = value;
}


