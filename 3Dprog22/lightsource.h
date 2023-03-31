#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "visualobject.h"

class LightSource : public VisualObject
{
public:
    LightSource();
    virtual void init(GLint matrixUniform) override;
    virtual void draw() override;

    GLfloat AmbientLightStrength {0.8};
    GLfloat AmbinetColour_x {0.3};
    GLfloat AmbinetColour_y {0.3};
    GLfloat AmbinetColour_z {0.3};

    GLfloat LightStrenght {0.7f};
    GLfloat LightColour_x {0.9f};
    GLfloat LightColour_y {0.9f};
    GLfloat LightColour_z {0.3f};

    GLfloat SpecularStrenght{0.9f};
    GLint mSpecularExponent{4};
};

#endif // LIGHTSOURCE_H
