// 3D-programmering 2022
#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"
#include "math.h"
#include <string>
#include "qimage.h"
#include <QOpenGLTexture>

class VisualObject : public QOpenGLFunctions_4_1_Core {
public:
   VisualObject();
   ~VisualObject();
   virtual void init(GLint matrixUniform)=0;
   virtual void draw()=0;
   virtual void move(float x, float y, float z);

   virtual QVector3D GetPos();
   virtual QVector3D GetColour();
   void setPos(QVector3D inPos);
   void setRotation(float a, float x, float y, float z); // Hope to manage rotation from here...

   float GetX();
   float GetY();
   float GetZ();
   float Coordinate_X = 0.0f;
   float Coordinate_Y = 0.0f;
   float Coordinate_Z = 0.0f;

   bool checkCube{false};
   bool checkGraph{false};
   bool checkXYZ{false};
   bool bRunTexture{true};
   bool bWireframe{false};
   //bHasHeightmap

   bool checkScene1{false};
   bool checkScene2{false};
   bool doorOpen = false;

   GLuint mVAO{0};
   GLuint mVBO{0};
   GLuint mEAB{0};

   QMatrix4x4 mMatrix;
   GLint mMatrixUniform{-1};

//protected:
   std::vector<Vertex> mVertices;
   std::vector<GLuint> mIndices;
   QMatrix4x4 mPosition;
   QMatrix4x4 mRotation;
   QMatrix4x4 mScale;
};
#endif // VISUALOBJECT_H
