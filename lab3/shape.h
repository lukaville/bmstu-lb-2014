#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    int vertexCount;
public:
    Shape() {
        vertexCount = 0;
    };
    int getVertexCount() const;
    void setVertexCount(int value);
};

#endif // SHAPE_H
