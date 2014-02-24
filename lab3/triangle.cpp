#include "triangle.h"


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
Color Triangle::getColor() const
{
    return color;
}

void Triangle::setColor(const Color &value)
{
    color = value;
}

std::istream &operator>>(std::istream &input, Triangle &triangle)
{
    std::cout << "Enter coordinates: \n";

    double x, y;
    input >> x >> y;
    triangle.setP1(Point(x, y));

    input >> x >> y;
    triangle.setP2(Point(x, y));

    input >> x >> y;
    triangle.setP3(Point(x, y));

    return input;
}

std::ostream &operator<<(std::ostream &output, Triangle &triangle)
{
    output << "Coordinates: \n";
    output << "Point 1: " << triangle.getP1().getX() << ", " << triangle.getP1().getY() << std::endl;
    output << "Point 2: " << triangle.getP2().getX() << ", " << triangle.getP2().getY() << std::endl;
    output << "Point 3: " << triangle.getP3().getX() << ", " << triangle.getP3().getY() << std::endl;
    output << "Color: rgb(" << triangle.getColor().getRed() << ", " << triangle.getColor().getGreen() << ", " << triangle.getColor().getBlue() << ")" << std::endl << std::endl;

    return output;
}

int Triangle::count = 0;
