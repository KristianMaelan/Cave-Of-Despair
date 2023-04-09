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

   virtual QVector3D GetPos();
   void setPos(QVector3D inPos);
   void setRotation(float a, float x, float y, float z); // Hope to manage rotation from here...

   float Coordinate_X;
   float Coordinate_Y;
   float Coordinate_Z;

   bool checkCube{false};
   bool checkGraph{false};
   bool checkXYZ{false};

   bool checkScene1{false};
   bool checkScene2{false};
   bool doorOpen = false;

   GLuint mVAO{0};
   GLuint mVBO{0};
   GLuint mEAB{0};

   QMatrix4x4 mMatrix;
   GLint mMatrixUniform{0};

protected:
   std::vector<Vertex> mVertices;
   std::vector<GLuint> mIndices;
   QMatrix4x4 mPosition;
   QMatrix4x4 mRotation;
   QMatrix4x4 mScale;
};
#endif // VISUALOBJECT_H
