#ifndef PLAYER1_H
#define PLAYER1_H

#include "visualobject.h"

class Player1 : public VisualObject
{
public:
    Player1();
    ~Player1() override;

    //inital positioning
    Player1(float x, float y, float z, float r, float g,float b);

    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;

    bool checkPlayerPresence{true};

    bool checkScene1{false};
    bool checkScene2{false};

   // GetLocation();
   void SetLocation(float x, float y, float z);

private:
    float mx, my, mz;

};

#endif // PLAYER1_H
