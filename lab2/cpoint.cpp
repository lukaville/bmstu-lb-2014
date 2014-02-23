#include "cpoint.h"


int CPoint::getX() const
{
    return x;
}

void CPoint::setX(int value)
{
    x = value;
}

int CPoint::getY() const
{
    return y;
}

void CPoint::setY(int value)
{
    y = value;
}

CPoint::CPoint()
{

}

CPoint::CPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}
