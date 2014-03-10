#include "rectangle.h"

Rectangle::Rectangle()
{
    this->p1 = CPoint<int>(0, 0);
    this->p2 = CPoint<int>(0, 0);
}

const Rectangle& operator++(Rectangle& i) {
    i.p1.setX(i.p1.getX() + 1);
    i.p1.setY(i.p1.getY() + 1);
    i.p2.setX(i.p2.getX() + 1);
    i.p2.setY(i.p2.getY() + 1);
    return i;
}

const Rectangle& operator--(Rectangle& i) {
    i.p1.setX(i.p1.getX() - 1);
    i.p1.setY(i.p1.getY() - 1);
    i.p2.setX(i.p2.getX() - 1);
    i.p2.setY(i.p2.getY() - 1);
    return i;
}

const Rectangle operator--(Rectangle& i, int) {
    Rectangle oldValue = i;
    i.p1.setX(i.p1.getX() - 1);
    i.p1.setY(i.p1.getY() - 1);
    i.p2.setX(i.p2.getX() - 1);
    i.p2.setY(i.p2.getY() - 1);
    return oldValue;
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
