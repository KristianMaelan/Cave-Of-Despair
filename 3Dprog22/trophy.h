#ifndef TROPHY_H
#define TROPHY_H

#include "cube.h"

class Trophy : public Cube
{
public:
    Trophy();
    Trophy(double x, double y, double z);
    ~Trophy();

    void init(GLint matrixUniform) override;
    void draw() override;

    VisualObject* trophyCube1;
    bool DidItemGetPickedUp = false;

    int NotTrophy = 0;
};

#endif // TROPHY_H
