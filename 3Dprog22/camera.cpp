#include "camera.h"

Camera::Camera() // : mEye{0,0,-5}
{
    // mPmatrix->setToIdentity();
    // mVmatrix->setToIdentity();
}

Camera::~Camera() { }

void Camera::init(GLint pMatrixUniform, GLint vMatrixUniform)
{
    mPmatrix.setToIdentity();
    mVmatrix.setToIdentity();

    mPmatrixUniform = pMatrixUniform;
    mVmatrixUniform = vMatrixUniform;

}

void Camera::perspective(int degrees, double aspect, double nearplane, double farplane)
{
    mPmatrix.perspective(degrees, aspect, nearplane, farplane);
}

void Camera::lookAt(const QVector3D &eye, const QVector3D &at, const QVector3D &up)
{
    mVmatrix.lookAt(eye, at, up);
}

void Camera::update()
{
    initializeOpenGLFunctions();

    glUniformMatrix4fv(mPmatrixUniform, 1, GL_FALSE, mPmatrix.constData());
    glUniformMatrix4fv(mVmatrixUniform, 1, GL_FALSE, mVmatrix.constData());
}

void Camera::move(float x, float y, float z)
{
    degrees += x;
    moveY += y;
    moveZ += z;


   mPmatrix.rotate(moveX, moveY, moveZ);

}

