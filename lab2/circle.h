#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

class Circle
{
friend std::ostream &operator<<(std::ostream &output, Circle &circle);
private:
    double x, y, radius;
public:
    Circle(double x, double y, double radius);
    double getRadius() const;
    void setRadius(double value);
    double getY() const;
    void setY(double value);
    double getX() const;
    void setX(double value);
    void print();
};



#endif // CIRCLE_H
