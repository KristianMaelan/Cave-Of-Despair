#ifndef INTERACTION_H
#define INTERACTION_H

#include "visualobject.h"

class Interaction : public VisualObject
{
public:
    Interaction();
    ~Interaction();
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;
// private:
    // position variables
    float moveX;
    float moveY;
    float moveZ;

    float PlayerLocation[3];
};

#endif // INTERACTION_H
