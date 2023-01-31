#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"

class Cube : public VisualObject
{
private:

public:
    Cube();
    ~Cube() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // CUBE_H
