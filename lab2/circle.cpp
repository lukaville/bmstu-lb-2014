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

void Circle::input()
{
    std::cout << "Enter circle center coordinates (x, y): ";
    std::cin >> x >> y;
    std::cout << "Enter radius: ";
    std::cin >> radius;
}

std::istream &operator>>(std::istream &input, Circle &circle)
{
    std::cout << "Enter circle center coordinates (x, y): ";
    input >> circle.x >> circle.y;
    std::cout << "Enter radius: ";
    input >> circle.radius;

    return input;
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
