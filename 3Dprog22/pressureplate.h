#ifndef PRESSUREPLATE_H
#define PRESSUREPLATE_H

#include "visualobject.h"

class PressurePlate : public VisualObject
{
public:
    PressurePlate(float x, float y, float z, float r, float g, float b);
    ~PressurePlate() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // PRESSUREPLATE_H
