template<typename T = int, int initFillType = 0>
class Line
{
protected:
    CPoint<T> p1;
    CPoint<T> p2;
    int lineWidth;
    int fillType;
public:
    Line()
    {
        this->p1 = CPoint<T>(0, 0);
        this->p2 = CPoint<T>(0, 0);
        this->lineWidth = 1;
        this->fillType = initFillType;
    }

    Line(CPoint<T> p1, CPoint<T> p2)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->lineWidth = 1;
        this->fillType = initFillType;
    }

    Line(CPoint<T> p1, CPoint<T> p2, int fillType, int lineWidth)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->lineWidth = lineWidth;
        this->fillType = fillType;
    }

    CPoint<T> getP1() const
    {
        return p1;
    }

    void setP1(const CPoint<T> &value)
    {
        p1 = value;
    }

    CPoint<T> getP2() const
    {
        return p2;
    }

    void setP2(const CPoint<T> &value)
    {
        p2 = value;
    }

    void print()
    {
        std::cout << "Заполнение: " << fillType << std::endl;
        std::cout << "Толщина линий: " << lineWidth << std::endl;
        std::cout << "x1 = " << p1.getX() << " у1 = " << p1.getY() << std::endl;
        std::cout << "x2 = " << p2.getX()  << " у2 = " << p2.getY() << std::endl;
    }

    int getLineWidth() const;
    void setLineWidth(int value);
    int getFillType() const;
    void setFillType(int value);

    void move(T dx, T dy);
};

template<typename T, int initFillType>
void Line<T, initFillType>::move(T dx, T dy)
{
    this->p1 = CPoint<T>(p1.getX() + dx, p1.getY() + dy);
    this->p2 = CPoint<T>(p2.getX() + dx, p2.getY() + dy);
}

template<>
class Line<short>
{
public:
    Line() {}

    void print() {
        std::cout << "short" << std::endl;
    };
};
















