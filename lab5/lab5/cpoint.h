#ifndef CPOINT_H
#define CPOINT_H

template<typename T>
class CPoint
{
private:
    T x, y;
public:
    CPoint(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    CPoint()
    {
        this->x = 0;
        this->y = 0;
    }
    T getX() const
    {
        return x;
    }
    void setX(const T &value)
    {
        x = value;
    }
    T getY() const
    {
        return y;
    }
    void setY(const T &value)
    {
        y = value;
    }
};


#endif // CPOINT_H
