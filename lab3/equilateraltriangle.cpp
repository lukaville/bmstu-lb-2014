#include "equilateraltriangle.h"

std::ostream &operator<<(std::ostream &output, EquilateralTriangle &triangle)
{
    output << "Coordinates: \n";
    output << "Point 1: " << triangle.getP1().getX() << ", " << triangle.getP1().getY() << std::endl;
    output << "Point 2: " << triangle.getP2().getX() << ", " << triangle.getP2().getY() << std::endl;
    output << "Point 3: " << triangle.getP3().getX() << ", " << triangle.getP3().getY() << std::endl;
    output << "Color: rgb(" << triangle.getColor().getRed() << ", " << triangle.getColor().getGreen() << ", " << triangle.getColor().getBlue() << ")" << std::endl << std::endl;
    output << "lineWidth: " << triangle.lineWidth << ", radius: " << triangle.radius << std::endl;

    return output;
}


void EquilateralTriangle::expandRadius(double delta)
{
    // protected property testing
    test = 1;

    this->radius += delta;
}
