#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point (double x, double y);

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);

private:
    double x, y;
};

#endif // POINT_H
