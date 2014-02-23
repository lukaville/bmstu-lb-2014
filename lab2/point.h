#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
friend std::ostream &operator<<(std::ostream &output, Point &point);
friend std::istream &operator>>(std::istream &input, Point &point);
private:
    double x, y;
public:
    Point(double x, double y);
    double getY() const;
    void setY(double value);
    double getX() const;
    void setX(double value);
    void print();
    void input();
};



#endif // CIRCLE_H
