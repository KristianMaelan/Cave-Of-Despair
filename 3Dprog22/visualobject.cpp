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

void VisualObject::setPos(QVector3D inPos)
{
    auto aA = mMatrix.column(3);
    aA.setX(inPos.x());
    aA.setY(inPos.y());
    aA.setZ(inPos.y());
    mMatrix.setColumn(3, aA);
}
