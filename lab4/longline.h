class LongLine : public Line<long>
{
private:
    int fillColor;
public:
    LongLine(CPoint<long> p1, CPoint<long> p2, int fillType, int lineWidth, int fillColor) : Line(p1, p2, fillType, lineWidth)
    {
        this->fillColor = fillColor;
    };
    void print() {
        std::cout << "Заполнение: " << fillType << std::endl;
        std::cout << "Толщина линий: " << lineWidth << std::endl;
        std::cout << "Цвет заливки: " << fillColor << std::endl;
        std::cout << "x1 = " << p1.getX() << " у1 = " << p1.getY() << std::endl;
        std::cout << "x2 = " << p2.getX()  << " у2 = " << p2.getY() << std::endl;
    }
};
