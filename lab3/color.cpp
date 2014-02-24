#include "color.h"

Color::Color()
{

}

Color::Color(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}
int Color::getRed() const
{
    return red;
}

void Color::setRed(int value)
{
    red = value;
}
int Color::getGreen() const
{
    return green;
}

void Color::setGreen(int value)
{
    green = value;
}
int Color::getBlue() const
{
    return blue;
}

void Color::setBlue(int value)
{
    blue = value;
}



