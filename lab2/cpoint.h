#ifndef CPOINT_H
#define CPOINT_H

class CPoint
{
private:
    int x, y;
public:
    CPoint();
    CPoint(int x, int y);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
};

#endif // CPOINT_H
