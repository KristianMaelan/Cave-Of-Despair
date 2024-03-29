#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"

class Cube : public VisualObject
{
public:
    Cube();
    ~Cube() override;
    Cube(float x, float y, float z, float r, float g,float b);
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z)override;
    QVector3D GetColour() override;

private:
    float mx, my, mz;
    float colourX, colourY, colourZ;
};

#endif // CUBE_H
