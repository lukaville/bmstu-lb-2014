#include "rectangle.h"

Rectangle::Rectangle()
{
    this->p1 = CPoint<int>(0, 0);
    this->p2 = CPoint<int>(0, 0);
}

std::istream &operator>>(std::istream &input, Rectangle &rectangle)
{
    std::cout << "Enter first point (x, y): ";

    int x, y;
    input >> x >> y;

    rectangle.p1.setX(x);
    rectangle.p1.setY(y);

    std::cout << "\nEnter second point (x, y): ";

    input >> x >> y;

    rectangle.p2.setX(x);
    rectangle.p2.setY(y);

    return input;
}

std::ostream &operator<<(std::ostream &output, Rectangle &rectangle) {
    output << "P1: (" << rectangle.p1.getX() << ", " << rectangle.p1.getY() << ")" << std::endl;
    output << "p2: (" << rectangle.p2.getX() << ", " << rectangle.p2.getY() << ")" << std::endl;
    return output;
}
