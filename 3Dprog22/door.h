#ifndef DOOR_H
#define DOOR_H

#include "visualobject.h"

class Door : public VisualObject
{
public:
    Door(float x, float y, float z, float r, float g, float b);
    ~Door() override;
    void init(GLint matrixUniform) override;
    void draw() override;

    bool doorOpen = false;
};

#endif // DOOR_H
