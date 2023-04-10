#ifndef HOUSE_H
#define HOUSE_H

#include "visualobject.h"

class house : public VisualObject
{
public:
    house();
    house(float x, float y, float z, float r, float g, float b);
    ~house() override;
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;

    QVector3D GetColour() override;

private:
    float colourX, colourY, colourZ;
};

#endif // HOUSE_H
