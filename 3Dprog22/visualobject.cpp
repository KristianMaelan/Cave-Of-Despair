// 3D-programmering 2022
#include "visualobject.h"

VisualObject::VisualObject()
{
    // Nødvendig å ha det her?
    mMatrix.setToIdentity();
    mPosition.setToIdentity();
    mRotation.setToIdentity();
    mScale.setToIdentity();
}

VisualObject::~VisualObject()
{
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}

void VisualObject::move(float x, float y, float z)
{

}

QVector3D VisualObject::GetPos()
{
    return mMatrix.column(3).toVector3D();
}

// Set position when constructing the object in renderwindow
void VisualObject::setPos(QVector3D inPos)
{
    auto aA = mMatrix.column(3);
    aA.setX(inPos.x());
    aA.setY(inPos.y());
    aA.setZ(inPos.z());
    mMatrix.setColumn(3, aA);


}

// Set rotation when constructing the object in renderwindow or use it to rotate object using user input
void VisualObject::setRotation(float a, float x, float y, float z)
{
    mMatrix.rotate(a, x, y, z);
}
