#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QWindow>
#include <QOpenGLFunctions_4_1_Core>
#include <QTimer>
#include <QElapsedTimer>
#include <vector>
#include "visualobject.h"
#include "camera.h"
#include "trophy.h"
#include "npc_grapher.h"
#include "player1.h"
#include "lightsource.h"
#include "heightmap.h"

class QOpenGLContext;
class Shader;
class MainWindow;
class Texture;
class LightSource;

/// This inherits from QWindow to get access to the Qt functionality and
// OpenGL surface.
// We also inherit from QOpenGLFunctions, to get access to the OpenGL functions
// This is the same as using "glad" and "glw" from general OpenGL tutorials
class RenderWindow : public QWindow, protected QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow);
    ~RenderWindow() override;

    QOpenGLContext *context() { return mContext; }

    void exposeEvent(QExposeEvent *) override;  //gets called when app is shown and resized

    bool mRotate{true};     //Check if triangle should rotate

    //float cameraX = 5;

private slots:
    void render();          //the actual render - function

private:
    void init();            //initialize things we need before rendering

    std::vector<VisualObject*> mObjects;
    std::vector<VisualObject*> TexturedObjects;

    VisualObject* InteractiveObject;    // new object for interaction possibilities WIP
    VisualObject* Comp1Cube;            // Movable cube
    VisualObject* KristianGraf;         // TriangleSurface readFile
    VisualObject* scene1_House;         // Oblig2 scene1_House
    VisualObject* scene1_Plan;          // Oblig2 scene1_Plan
    VisualObject* scene1_PressurePlate; // Oblig2 scene1_PressurePlate
    VisualObject* scene1_Door;          // Oblig2 scene1_Door
    Player1* Player;               // Player1 Pointer
    std::vector<VisualObject*> PlayerList;
    VisualObject* ObjectInHouse;        // Oblig2 Object inside house

    heightmap* Heightmap;

    bool doorOpen = false;

    bool Scene1 = false;
    bool Scene2 = false;
    bool wireframeOn = false;


    // trophy
    Trophy* trophyCube1;           // pickup item (for oblig2)
    Trophy* trophyCube2;
    Trophy* trophyCube3;
    Trophy* trophyCube4;
    Trophy* trophyCube5;
    Trophy* trophyCube6;
    std::vector<Trophy*> trophyList;

    void     setObjectPositionInScene(); // This is to help us set positions after the constructor, see trophies

    // NPC
    NPC_grapher* Walker;
    NPC_grapher* graph_1_Walker;
    NPC_grapher* graph_2_Walker;
    std::vector<NPC_grapher*> npclist;
    std::vector<NPC_grapher*> graph1List;
    std::vector<NPC_grapher*> graph2List;

    // LightSource -- Oblig 3
    LightSource* LightSourceObject;
    std::vector<class LightSource*> LightSourceList;

    // collision
    bool CollisionDetection(VisualObject* player, VisualObject* wordl_object);

    // NPC
    NPC_grapher* NPC;                   // NPC

    // camera
    Camera* mCamera{};
    float x_Axis = 0.f;
    float y_Axis = 0.f;
    float z_Axis = 5.f;

    QOpenGLContext *mContext{nullptr};  //Our OpenGL context
    bool mInitialized{false};

    /// things needed for Shaders, such as uniform and setup functions
    // holds pointer the GLSL shader program
    Shader *mShaderProgram[4]{nullptr};
    Shader* ptr_plainShaderProgram;
    Shader* ptr_textureShaderProgram;
    Shader* ptr_phongShaderProgram;

    GLint  mPmatrixUniform{-1};
    GLint  mVmatrixUniform{-1};
    GLint  mMmatrixUniform{-1};

    void setUpPlainShader(GLint shaderElement);

    void setUpTextureShader(GLint shaderElement);
    GLint mPmatrixUniform1{-1};
    GLint mVmatrixUniform1{-1};
    GLint mMmatrixUniform1{-1};
    GLint mSampler2Dtexture{-1};

    void setUpPhongShader(GLint shaderElement);

    GLint mAmbientStrength{-1};
    GLint mLightPosition{-1};
    GLint mCameraPosition{-1};
    GLint mLightColour{-1};
    GLint mObjectColour{-1};
    GLint mLightPower{-1};
    GLint mSpecularStrenght{-1};
    GLint mSpecularExponent{-1};

    /// done with shader

    GLuint mVAO;                        //OpenGL reference to our VAO
    GLuint mVBO;                        //OpenGL reference to our VBO

    //QMatrix4x4 *mMVPmatrix{nullptr};         //The matrix with the transform for the object we draw
    //QMatrix4x4 *mPmatrix{nullptr};         // Leksjon 3
    //QMatrix4x4 *mVmatrix{nullptr};         // Leksjon 3

    QTimer *mRenderTimer{nullptr};           //timer that drives the gameloop
    QElapsedTimer mTimeStart;               //time variable that reads the calculated FPS

    MainWindow *mMainWindow{nullptr};        //points back to MainWindow to be able to put info in StatusBar

    class QOpenGLDebugLogger *mOpenGLDebugLogger{nullptr};  //helper class to get some clean debug info from OpenGL
    class Logger *mLogger{nullptr};         //logger - Output Log in the application


    ///Helper function that uses QOpenGLDebugLogger or plain glGetError()
    void checkForGLerrors();

    void calculateFramerate();          //as name says

    ///Starts QOpenGLDebugLogger if possible
    void startOpenGLDebugger();

protected:
    //The QWindow that we inherit from have these functions to capture
    // - mouse and keyboard.
    // Uncomment to use (you also have to make the definitions of
    // these functions in the cpp-file to use them of course!)
    //
    //    void mousePressEvent(QMouseEvent *event) override{}
    //    void mouseMoveEvent(QMouseEvent *event) override{}
    void keyPressEvent(QKeyEvent *event) override;              //the only one we use now
    //    void keyReleaseEvent(QKeyEvent *event) override{}
    //    void wheelEvent(QWheelEvent *event) override{}

    /*  move camera?? */


};

#endif // RENDERWINDOW_H
