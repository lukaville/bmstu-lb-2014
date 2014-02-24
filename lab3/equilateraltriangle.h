#include "triangle.h"

#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

class EquilateralTriangle : public Triangle
{
friend std::ostream &operator<<(std::ostream &output, EquilateralTriangle &triangle);

public:
    EquilateralTriangle()
    {
        lineWidth = 0;
        radius = 0;
    }

    EquilateralTriangle(std::string name) : Triangle(name)
    {
        lineWidth = 0;
        radius = 0;
    }

    EquilateralTriangle(Point p1, Point p2, Point p3, Color color, double lineWidth, double radius) : Triangle(p1, p2, p3, color)
    {
        this->lineWidth = lineWidth;
        this->radius = radius;
    }

    ~EquilateralTriangle()
    {
        // nothing
    }

    void expandRadius(double delta);

    double lineWidth;
    double radius;
};

#endif // EQUILATERALTRIANGLE_H
