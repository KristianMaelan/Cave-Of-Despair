#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
   TriangleSurface();
   ~TriangleSurface() override;
   void init(GLint matrixUniform) override;
   void draw() override;
};

#endif // TRIANGLESURFACE_H
