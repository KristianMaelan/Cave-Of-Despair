#ifndef GRAPHER_H
#define GRAPHER_H

#include "visualobject.h"

class grapher : public VisualObject
{
public:
    grapher();
    ~grapher() override;
    void init(GLint matrixUniform) override;
    void draw() override;
};

#endif // GRAPHER_H
