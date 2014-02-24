#include "triangle.h"

#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

class EquilateralTriangle : public Triangle
{
friend std::ostream &operator<<(std::ostream &output, EquilateralTriangle &triangle);

public:
    EquilateralTriangle()
    {
        p1 = Point(0, 0);
        p2 = Point(0, 0);
        p3 = Point(0, 0);
        color = Color(0, 0, 0);
    }

    EquilateralTriangle(Point p1, Point p2, Point p3)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->color = Color(0, 0, 0);
    }

    EquilateralTriangle(Point p1, Point p2, Point p3, Color color)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->color = color;
    }

    ~EquilateralTriangle()
    {
        // nothing
    }
};

#endif // EQUILATERALTRIANGLE_H
