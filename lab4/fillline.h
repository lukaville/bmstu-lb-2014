template <typename T> class FillLine : public Line<T>
{
private:
    int fillColor;
public:
    FillLine()
    {
        this->fillColor = 0;
    };
    void print() {
        std::cout << "Заполнение: " << this->fillType << std::endl;
        std::cout << "Толщина линий: " << this->lineWidth << std::endl;
        std::cout << "Цвет заливки: " << this->fillColor << std::endl;
        std::cout << "x1 = " << this->p1.getX() << " у1 = " << this->p1.getY() << std::endl;
        std::cout << "x2 = " << this->p2.getX()  << " у2 = " << this->p2.getY() << std::endl;
    }
};
