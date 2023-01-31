// 3D-programmering 2022
#ifndef XYZ_H
#define XYZ_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "visualobject.h"

class XYZ : public VisualObject
{
private:

public:
   XYZ();
   ~XYZ() override;
   void init(GLint matrixUniform) override;
   void draw() override;
};
#endif // XYZ_H
