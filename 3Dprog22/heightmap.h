#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "visualobject.h"
//#ifndef STB_IMAGE_IMPLEMENTATION


class heightmap : public VisualObject
{
public:
    heightmap();
    heightmap(const char* imgPath);
    heightmap(const char* imgPath, float r, float g, float b);
    ~heightmap() override;
    void init(GLint matrixUniform) override;
    void draw() override;
    float getTerrainHeight(const QVector2D pointInSpace);
    QVector3D getBary(const QVector2D& a, const QVector2D& b, const QVector2D& c, const QVector2D& x);
};

//#endif // STB_IMAGE_IMPLEMENTATION
#endif // HEIGHTMAP_H
