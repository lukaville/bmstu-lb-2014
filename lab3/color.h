#ifndef COLOR_H
#define COLOR_H

#include <string>

class Color
{
public:
    Color();
    Color(int red, int green, int blue);

    int getRed() const;
    void setRed(int value);

    int getGreen() const;
    void setGreen(int value);

    int getBlue() const;
    void setBlue(int value);

    std::string toString();

private:
    int red, green, blue;
};

#endif // COLOR_H
