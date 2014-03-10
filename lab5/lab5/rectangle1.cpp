#include "rectangle1.h"

Rectangle1::Rectangle1()
{
    this->p1 = CPoint<int>(0, 0);
    this->p2 = CPoint<int>(0, 0);
}

const Rectangle1& operator++(Rectangle1& i) {
    i.p1.setX(i.p1.getX() + 1);
    i.p1.setY(i.p1.getY() + 1);
    i.p2.setX(i.p2.getX() + 1);
    i.p2.setY(i.p2.getY() + 1);
    return i;
}

const Rectangle1& operator--(Rectangle1& i) {
    i.p1.setX(i.p1.getX() - 1);
    i.p1.setY(i.p1.getY() - 1);
    i.p2.setX(i.p2.getX() - 1);
    i.p2.setY(i.p2.getY() - 1);
    return i;
}

const Rectangle1 operator--(Rectangle1& i, int) {
    Rectangle1 oldValue = i;
    i.p1.setX(i.p1.getX() - 1);
    i.p1.setY(i.p1.getY() - 1);
    i.p2.setX(i.p2.getX() - 1);
    i.p2.setY(i.p2.getY() - 1);
    return oldValue;
}

std::istream &operator>>(std::istream &input, Rectangle1 &rectangle)
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

std::ostream &operator<<(std::ostream &output, Rectangle1 &rectangle) {
    output << "P1: (" << rectangle.p1.getX() << ", " << rectangle.p1.getY() << ")" << std::endl;
    output << "p2: (" << rectangle.p2.getX() << ", " << rectangle.p2.getY() << ")" << std::endl;
    return output;
}

const Rectangle1 operator+(const Rectangle1& left, const Rectangle1& right) {
    Rectangle1 r;
    r.p1.setX(left.p1.getX() + right.p1.getX());
    r.p1.setY(left.p1.getY() + right.p1.getY());
    r.p2.setX(left.p2.getX() + right.p2.getX());
    r.p2.setY(left.p2.getY() + right.p2.getY());
    return r;
}


const Rectangle1 operator-(const Rectangle1 &left, const Rectangle1 &right)
{
    Rectangle1 r;
    r.p1.setX(left.p1.getX() - right.p1.getX());
    r.p1.setY(left.p1.getY() - right.p1.getY());
    r.p2.setX(left.p2.getX() - right.p2.getX());
    r.p2.setY(left.p2.getY() - right.p2.getY());
    return r;
}

const Rectangle1 operator*(const Rectangle1 &left, const Rectangle1 &right)
{
    Rectangle1 r;
    r.p1.setX(left.p1.getX() * right.p1.getX());
    r.p1.setY(left.p1.getY() * right.p1.getY());
    r.p2.setX(left.p2.getX() * right.p2.getX());
    r.p2.setY(left.p2.getY() * right.p2.getY());
    return r;
}
