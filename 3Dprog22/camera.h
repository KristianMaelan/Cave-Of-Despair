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
    // move camera??
    void move(float x, float y, float z);
    void getRotated(float a, float x, float y, float z);
private:
    GLint  mPmatrixUniform;             // Leksjon 3
    GLint  mVmatrixUniform;             // Leksjon 3
    QVector3D mEye;
    //QMatrix4x4 *mPmatrix{nullptr};         // Leksjon 3
    //QMatrix4x4 *mVmatrix{nullptr};         // Leksjon 3
    QMatrix4x4 mPmatrix{ };
    QMatrix4x4 mVmatrix{ };

    // move camera??
    float degrees;
    float moveX;
    float moveY;
    float moveZ;

};

#endif // CAMERA_H
