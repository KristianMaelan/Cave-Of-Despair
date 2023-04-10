#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "visualobject.h"
#include <qvector3d.h>

class LightSource : public VisualObject
{
public:
    LightSource();
    void init(GLint matrixUniform) override;
    void draw() override;

    // QVector3D GetPos() override;

    GLfloat AmbientLightStrength {0.1};
    QVector3D AmbinetColour {0.3, 0.3, 0.3};

    GLfloat LightStrenght {0.7f};
    QVector3D LightColour {0.9, 0.9, 0.3};

    GLfloat SpecularStrenght{0.9f};
    GLint mSpecularExponent{4};
};

#endif // LIGHTSOURCE_H
