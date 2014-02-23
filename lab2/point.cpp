#include "point.h"
#include <iostream>

double Point::getY() const
{
    return y;
}

void Point::setY(double value)
{
    y = value;
}

double Point::getX() const
{
    return x;
}

void Point::setX(double value)
{
    x = value;
}

void Point::print()
{
    std::cout << "Center: (" << x << ", " << y << ")";
}

void Point::input()
{
    std::cout << "Enter point center coordinates (x, y): ";
    std::cin >> x >> y;
}

std::istream &operator>>(std::istream &input, Point &point)
{
    std::cout << "Enter point center coordinates (x, y): ";
    input >> point.x >> point.y;

    return input;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

std::ostream &operator<<(std::ostream &output, Point &point) {
    output << "Center: (" << point.getX() << ", " << point.getY() << ")";
    return output;
}
