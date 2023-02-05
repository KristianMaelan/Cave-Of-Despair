#ifndef CUBE_H
#define CUBE_H

#include <QWindow>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QElapsedTimer>
#include "visualobject.h"

class Cube : public VisualObject
{
public:
    Cube();
    Cube(float x, float y, float z, float r, float g,float b);
    ~Cube() override;

    void rotation(QKeyEvent *event);

    void init(GLint matrixUniform) override;
    void draw() override;

    void move(float x, float y, float z);

private:
    float mx, my, mz;
};

#endif // CUBE_H
