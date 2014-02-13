#include "circle.h"
#include <iostream>

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double value)
{
    radius = value;
}

double Circle::getY() const
{
    return y;
}

void Circle::setY(double value)
{
    y = value;
}

double Circle::getX() const
{
    return x;
}

void Circle::setX(double value)
{
    x = value;
}

void Circle::print()
{
    std::cout << "Center: (" << x << ", " << y << "), radius: " << radius;
}

Circle::Circle(double x, double y, double radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

std::ostream &operator<<(std::ostream &output, Circle &circle) {
    output << "Center: (" << circle.getX() << ", " << circle.getY() << "), radius: " << circle.getRadius();
    return output;
}
