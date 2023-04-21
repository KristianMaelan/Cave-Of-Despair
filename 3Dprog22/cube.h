#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"
#include "logger.h"

class Cube : public VisualObject
{
public:
    Cube();
    ~Cube() override;
    Cube(float x, float y, float z, float r, float g,float b);
    Cube(float x, float y, float z, float r, float g,float b, float u, float v);
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z)override;
    QVector3D GetColour() override;

private:
    float mx, my, mz;
    float colourX, colourY, colourZ;
};

#endif // CUBE_H
