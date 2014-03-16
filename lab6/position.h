#ifndef POSITION_H
#define POSITION_H

class _POSITION
{
private:
    int i = 0;
public:
    _POSITION(int i) {
        this->i = i;
    };
    void plus() {
        i++;
    }

    void minus() {
        i--;
    }

    int getI() const;
    void setI(int value);
};

#endif // POSITION_H

int _POSITION::getI() const
{
    return i;
}

void _POSITION::setI(int value)
{
    i = value;
}

typedef _POSITION* POSITION;
