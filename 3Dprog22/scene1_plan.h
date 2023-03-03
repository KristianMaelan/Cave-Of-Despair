#ifndef SCENE1_PLAN_H
#define SCENE1_PLAN_H

#include "visualobject.h"

class Scene1_plan : public VisualObject
{
public:
    Scene1_plan();
    Scene1_plan(float x, float y, float z, float r, float g, float b);
    ~Scene1_plan() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // SCENE1_PLAN_H
