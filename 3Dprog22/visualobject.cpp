// 3D-programmering 2022
#include "visualobject.h"

VisualObject::VisualObject() {  }
VisualObject::~VisualObject()
{
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}
void VisualObject::move(float x, float y, float z) {    }
