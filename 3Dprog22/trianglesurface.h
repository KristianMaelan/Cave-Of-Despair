#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
   TriangleSurface();
   TriangleSurface(std::string fileName);
   ~TriangleSurface() override;
   void readFile(std::string fileName);
   void init(GLint matrixUniform) override;
   void draw() override;
};

#endif // TRIANGLESURFACE_H
