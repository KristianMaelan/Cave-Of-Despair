// 3D-programmering 2022
#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "math.h"

class VisualObject : public QOpenGLFunctions_4_1_Core {
public:
   VisualObject();
   ~VisualObject();
   virtual void init(GLint matrixUniform)=0;
   virtual void draw()=0;
   virtual void move(float x, float y, float z);

   QVector3D GetPos();
   void setPos(QVector3D inPos);

   bool checkCube{false};
   bool checkGraph{false};
   bool checkXYZ{false};
   bool checkScene1{false};
   bool checkScene2{false};
protected:
   std::vector<Vertex> mVertices;
   GLuint mVAO{0};
   GLuint mVBO{0};
   GLint mMatrixUniform{0};
   QMatrix4x4 mMatrix;
   QMatrix4x4 mPosition;
   QMatrix4x4 mRotation;
   QMatrix4x4 mScale;
};
#endif // VISUALOBJECT_H
