#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "iostream"
#include "color.h"
#include "point.h"

class Triangle
{
friend std::ostream &operator<<(std::ostream &output, Triangle &triangle);
friend std::istream &operator>>(std::istream &input, Triangle &triangle);

public:
    Triangle()
    {
        std::cout << "tdsfojdsmkd";
        p1 = Point(0, 0);
        p2 = Point(0, 0);
        p3 = Point(0, 0);
        color = Color(0, 0, 0);
    }

    Triangle(Point p1, Point p2, Point p3)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->color = Color(0, 0, 0);
    }

    Triangle(Point p1, Point p2, Point p3, Color color)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->color = color;
    }

    //~Triangle()
    //{
        //nothing to do
    //}

    Point getP1() const;
    void setP1(const Point &value);

    Point getP2() const;
    void setP2(const Point &value);

    Point getP3() const;
    void setP3(const Point &value);


    Color getColor() const;
    void setColor(const Color &value);



private:
    Point p1, p2, p3;
    Color color;
};

#endif // TRIANGLE_H
