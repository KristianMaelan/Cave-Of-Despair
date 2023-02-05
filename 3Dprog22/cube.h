#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"

class Cube : public VisualObject
{
private:

public:
    Cube();
    ~Cube() override;
    Cube(float x, float y, float z, float r, float g,float b);
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // CUBE_H
