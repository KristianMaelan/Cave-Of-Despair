#ifndef CAMERA_H
#define CAMERA_H

#include <QOpenGLFunctions_4_1_Core>
#include <QVector3D>
#include <QMatrix4x4>

class Camera : public QOpenGLFunctions_4_1_Core
{
public:
    Camera();
    ~Camera();
    void init(GLint pMatrixUniform, GLint vMatrixUniform);
    void perspective(int degrees, double aspect, double nearplace, double farplace);
    void lookAt(const QVector3D &eye, const QVector3D &at, const QVector3D &up);
    void update();
    void translate(float dx, float dy, float dz);
private:
    GLint  mPmatrixUniform;             // Leksjon 3
    GLint  mVmatrixUniform;             // Leksjon 3
    QVector3D mEye;
    QMatrix4x4 mPmatrix{ };         // Leksjon 3
    QMatrix4x4 mVmatrix{ };         // Leksjon 3

};

#endif // CAMERA_H