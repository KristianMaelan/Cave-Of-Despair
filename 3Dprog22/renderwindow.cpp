#include "renderwindow.h"
#include <QTimer>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLDebugLogger>
#include <QKeyEvent>
#include <QStatusBar>
#include <QDebug>

#include <string>
#include <iostream>

#include "lightsource.h"
#include "shader.h"
#include "player1.h"
#include "mainwindow.h"
#include "logger.h"
//#include "xyz.h"
#include "cube.h"
//#include "interaction.h"
//#include "trianglesurface.h"
#include "house.h"
#include "scene1_plan.h"
#include "pressureplate.h"
#include "trophy.h"
#include "door.h"
//#include "lightsource.h"

RenderWindow::RenderWindow(const QSurfaceFormat &format, MainWindow *mainWindow)
    : mContext(nullptr), mInitialized(false), mMainWindow(mainWindow)

{
    //This is sent to QWindow:
    setSurfaceType(QWindow::OpenGLSurface);
    setFormat(format);
    //Make the OpenGL context
    mContext = new QOpenGLContext(this);
    //Give the context the wanted OpenGL format (v4.1 Core)
    mContext->setFormat(requestedFormat());
    if (!mContext->create()) {
        delete mContext;
        mContext = nullptr;
        qDebug() << "Context could not be made - quitting this application";
    }

        std::cout << "we reached 'mContext";
    //Camera setup
    mCamera = new Camera;

    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);

    // mObjects.push_back(new XYZ());
    // mObjects.push_back(new TriangleSurface());

    // interaction with object
    // mObjects.push_back(new Interaction());
    // InteractiveObject = new Interaction;
    // mObjects.push_back(InteractiveObject);

    //// CAMERA


    // Askelad-cube
   Comp1Cube = new Cube(0.5,0.5,0.5,1,0.5,0.5);
   mObjects.push_back(Comp1Cube);
    // Comp1Cube = new Cube;
    // mObjects.push_back(new Cube(0.5,0.5,0.5,1,0.5,0.5));

    // from tempReadMe, needs to be changed depending
    //KristianGraf = new TriangleSurface("../3Dprog22/info.txt");
    //mObjects.push_back(KristianGraf);

    // Oblig2 - Scene1_House
    scene1_House = new house(1, 1, 1, 0.2, 0.5, 0.3); // Create with dimensions
    scene1_House->setPos(QVector3D{3, 0, -2});   // Set position
    scene1_House->setRotation(135, 0, 1, 0);    // Set rotation
    mObjects.push_back(scene1_House);

    //scene1_House->setPos(QVector3D{0, 0, 0});   // Set position

    //mObjects.push_back(scene1_House);

    // Oblig2 - Scene1_PressurePlate dimensions
    scene1_PressurePlate = new PressurePlate(1, 1, 1, 1, 0, 0);
    scene1_PressurePlate->setPos(QVector3D{3, 0.00001, -2});
    scene1_PressurePlate->setRotation(135, 0, 1, 0);
    mObjects.push_back(scene1_PressurePlate);

    // Oblig2 - Scene1_Plan
    scene1_Plan = new Scene1_plan(5, -1, 5, 0.58, 0.30, 0);
    mObjects.push_back(scene1_Plan);

    // programming 2 - (1) IS IT POSSIBLE TO PUT IN A FOR LOOP TO MAKE SEVERAL CUBES? YES, BUT NEED CAMERA TO SEE WHAT IT REALLY LOOKS LIKE, BECAUSE THE SCREEN IS YELLOW
    //float trophyX = 0.1;
    //float trophyY = 0.1;
    //float trophyZ = 0.1;

    // (2) UNCOMMENT WHEN YOU WANT ALL YOUR TROPHIES
    //for (int i = 0; i < 7; ++i)
    //{
      //  trophyCube = new Trophy(trophyX, trophyY, trophyZ);
        //trophyList.push_back(trophyCube);
     // mObjects.push_back(trophyCube);
     // trophyX += 2.0f;
     // trophyZ += 0.5f;
        //for (float x = 0; x < 7; ++x)
        //{
        //  trophyList[i]->setPos(QVector3D{trophyX, trophyY, 0.1});
        //}
      // std::cout << "we have new trophies" << i << "\n";
    //}

    trophyCube1 = new Trophy(0.1, -0.6, 0.1);
    trophyCube1->setPos(QVector3D{0, 0, 0});
    trophyList.push_back(trophyCube1);

    trophyCube2 = new Trophy(0.1, -0.6, 0.1);
    trophyCube2->setPos(QVector3D{1.7, 0, 0});
    trophyList.push_back(trophyCube2);

    trophyCube3 = new Trophy(0.1, -0.6, 0.1);
    trophyCube3->setPos(QVector3D{2.4, 0, 0});
    trophyList.push_back(trophyCube3);

    trophyCube4 = new Trophy(0.1, -0.6, 0.1);
    trophyCube4->setPos(QVector3D{3.1, 0, 0});
    trophyList.push_back(trophyCube4);

    trophyCube5 = new Trophy(0.1, -0.6, 0.1);
    trophyCube5->setPos(QVector3D{4.8, 0, 0});
    trophyList.push_back(trophyCube5);

    trophyCube6 = new Trophy(0.1, -0.6, 0.1);
    trophyCube6->setPos(QVector3D{5.5, 0, 0});
    trophyList.push_back(trophyCube6);

    /*float npc_x = 0.4f;
    float npc_y = 0.6f;
    float npc_z = 0.0f;

    NPC = new NPC_grapher(npc_x, npc_y, npc_z);
    mObjects.push_back(NPC);*/

//    float npc_x = 0.4f;
//    float npc_y = 0.6f;
//    float npc_z = 0.0f;

//    NPC = new NPC_grapher(npc_x, npc_y, npc_z);
//    mObjects.push_back(NPC);


    // Oblig 2 - Scene1_Door
    scene1_Door = new Door(1, 1, 1, 0, 0, 1);
    scene1_Door->setPos(QVector3D{3, 0, -2});
    scene1_Door->setRotation(135, 0, 1, 0);
    mObjects.push_back(scene1_Door);

    // Object in house test - Joakim
    ObjectInHouse = new house(0.2, 0.2, 0.2, 1, 0, 0);
    ObjectInHouse->setPos(QVector3D{0, -1, 1});
    ObjectInHouse->setRotation(180, 0, 1, 0);
    mObjects.push_back(ObjectInHouse);

    {
        Player = new Player1(0.5,0.5,0.5,0.4,0.2,0.6);
        mObjects.push_back(Player);
    }


    // NPC Walker
    Walker = new NPC_grapher(0.5,0.5,0.5);
    mObjects.push_back(Walker);
    //npclist.push_back(Walker);
    Walker->functionMove();

    // this is our lightsource, should look like a pyramid
    LightSourceObject = new LightSource();
    LightSourceList.push_back(LightSourceObject);
    //LightSourceList.push_back(new LightSource);


    // Kan være denne må være i init? evt mObjects.push_back
    //heightmap = new loglheightmap("../3Dprog22/heightmap.bmp");
    //mObjects.push_back(heightmap); // Yes or No?

}

RenderWindow::~RenderWindow()
{
    //cleans up the GPU memory
    glDeleteVertexArrays( 1, &mVAO );
    glDeleteBuffers( 1, &mVBO );
}

// Sets up the general OpenGL stuff and the buffers needed to render a triangle
void RenderWindow::init()
{
    //Get the instance of the utility Output logger
    //Have to do this, else program will crash (or you have to put in nullptr tests...)
    mLogger = Logger::getInstance();

    //Connect the gameloop timer to the render function:
    //This makes our render loop
    connect(mRenderTimer, SIGNAL(timeout()), this, SLOT(render()));
    //********************** General OpenGL stuff **********************

    //The OpenGL context has to be set.
    //The context belongs to the instanse of this class!
    if (!mContext->makeCurrent(this)) {
        mLogger->logText("makeCurrent() failed", LogType::REALERROR);
        return;
    }

    //just to make sure we don't init several times
    //used in exposeEvent()
    if (!mInitialized)
        mInitialized = true;

    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    //Print render version info (what GPU is used):
    //Nice to see if you use the Intel GPU or the dedicated GPU on your laptop
    // - can be deleted
    mLogger->logText("The active GPU and API:", LogType::HIGHLIGHT);
    std::string tempString;
    tempString += std::string("  Vendor: ") + std::string((char*)glGetString(GL_VENDOR)) + "\n" +
            std::string("  Renderer: ") + std::string((char*)glGetString(GL_RENDERER)) + "\n" +
            std::string("  Version: ") + std::string((char*)glGetString(GL_VERSION));
    mLogger->logText(tempString);

    //Start the Qt OpenGL debugger
    //Really helpfull when doing OpenGL
    //Supported on most Windows machines - at least with NVidia GPUs
    //reverts to plain glGetError() on Mac and other unsupported PCs
    // - can be deleted
    startOpenGLDebugger();

    //general OpenGL stuff:
    glEnable(GL_DEPTH_TEST);            //enables depth sorting - must then use GL_DEPTH_BUFFER_BIT in glClear
    //    glEnable(GL_CULL_FACE);       //draws only front side of models - usually what you want - test it out!
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);    //gray color used in glClear GL_COLOR_BUFFER_BIT

    //Compile shaders:
    //NB: hardcoded path to files! You have to change this if you change directories for the project.
    //Qt makes a build-folder besides the project folder. That is why we go down one directory
    // (out of the build-folder) and then up into the project folder.
    //
        std::cout << "we reached 'renderwindow.cpp";
    mShaderProgram[0] = new Shader( "../3Dprog22/phongshader.vert" , "../3Dprog22/plainshader.frag");
    mShaderProgram[1] = new Shader( "../3Dprog22/phongshader.vert" , "../3Dprog22/textureshader.frag");
    mShaderProgram[2] = new Shader( "../3Dprog22/phongshader.vert" , "../3Dprog22/phongshader.frag");

    mPmatrixUniform = glGetUniformLocation( mShaderProgram[2]->getProgram(), "pMatrix" );
    mVmatrixUniform = glGetUniformLocation( mShaderProgram[2]->getProgram(), "vMatrix" );
    mMmatrixUniform = glGetUniformLocation( mShaderProgram[2]->getProgram(), "matrix" );

//    setUpPlainShader(0);
    setUpTextureShader(1);
    setUpPhongShader(2);

    /*setupPlainShader(0);
    setupTextureShader(1);
    setupPhongShader(2);*/

    // Get the matrixUniform location from the shader
    // This has to match the "matrix" variable name in the vertex shader
    // The uniform is used in the render() function to send the model matrix to the shader


    //mCamera->init(mPmatrixUniform, mVmatrixUniform);
    mCamera->init(mPmatrixUniform, mPmatrixUniform);
    Logger::getInstance()->logText("RenderWindow; init camera");

    // mCamera.init(mPmatrixUniform, mVmatrixUniform);
    // use mMatrixUniform2 on the things affected by the phong shader (light model)

    glUseProgram( mShaderProgram[2]->getProgram() );

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        //(*it)->init(mMmatrixUniform);
        (*it)->init(mMmatrixUniform);
    }
    for (auto trophy_nr = trophyList.begin(); trophy_nr != trophyList.end(); ++trophy_nr)
    {
        //(*trophy_nr)->init(mMmatrixUniform);
        (*trophy_nr)->init(mMmatrixUniform);
    }
    for (auto npc_nr = npclist.begin(); npc_nr < npclist.end(); ++npc_nr)
    {
        //(*npc_nr)->init(mMmatrixUniform);
        (*npc_nr)->init(mMmatrixUniform);
    }
    for (auto player_nr = PlayerList.begin(); player_nr < PlayerList.end(); ++player_nr)
    {
        (*player_nr)->init(mMmatrixUniform);
    }
    for (auto LightSourceList_thing = LightSourceList.begin(); LightSourceList_thing < LightSourceList.end(); ++LightSourceList_thing)
    {
        (*LightSourceList_thing)->init(mMmatrixUniform);
    }


    Logger::getInstance()->logText("RenderWindow; for auto loop");

    // Mo
    // Ingen feilkode, men vises ikkje...
    //heightmap = new loglheightmap("../3Dprog22/heightmap4.bmp");
    // Denne ligger i Ole Flatens kode
    //heightmap->init(mMmatrixUniform);


    glBindVertexArray(0);       //unbinds any VertexArray - good practice
}

bool RenderWindow::CollisionDetection(VisualObject *player, VisualObject *world_object)
{
    bool CollidedWith_X = player->Coordinate_X + 0.5 >= world_object->Coordinate_X && world_object->Coordinate_X + 0.5 >= player->Coordinate_X;
    bool CollidedWith_Y = player->Coordinate_Y + 0.5 >= world_object->Coordinate_Y && world_object->Coordinate_Y + 0.5 >= player->Coordinate_Y;
    return CollidedWith_X && CollidedWith_Y;
}

void RenderWindow::setUpPlainShader(GLint shaderElement)
{


    Logger::getInstance()->logText("Renderwindow; setUpPlainShader; uniforms done ");
}

void RenderWindow::setUpTextureShader(GLint shaderElement)
{
    mSampler2Dtexture = glGetUniformLocation( mShaderProgram[shaderElement]->getProgram(), "textureSampler");

    Logger::getInstance()->logText("Renderwindow; setUpPlainShader; uniforms done ");
}

void RenderWindow::setUpPhongShader(GLint shaderElement)
{
    mAmbientStrength = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "ambientStrength");
    mLightPosition = glGetUniformLocation( mShaderProgram[shaderElement]->getProgram(), "lightPosition" );
    mCameraPosition = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "cameraPosition");
    mLightColour = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "lightColor");
    mObjectColour = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "objectColor");
    mLightPower = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "lightPower");
    mSpecularStrenght = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "specularStrength");
    mSpecularExponent = glGetUniformLocation(mShaderProgram[shaderElement]->getProgram(), "specularExponent");

    Logger::getInstance()->logText("Renderwindow; setUpPlainShader; uniforms done ");
}

// Called each frame - doing the rendering!!!
void RenderWindow::render()
{
    mCamera->init(mPmatrixUniform, mVmatrixUniform);
   // mCamera->perspective(60, 4.0/3.0, 0.1, 20.0);

    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this); //must be called every frame (every time mContext->swapBuffers is called)

    initializeOpenGLFunctions();    //must call this every frame it seems...

    //clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glUseProgram(mShaderProgram[2]->getProgram());
    // camara information
//    mCamera->init(mPmatrixUniform, mVmatrixUniform);
    glUniformMatrix4fv(mVmatrixUniform, 1, GL_TRUE, mCamera->mVmatrix.constData());
    glUniformMatrix4fv(mPmatrixUniform, 1, GL_TRUE, mCamera->mPmatrix.constData());
    {
        // Camera movement
        if (Scene1){
            mCamera->perspective(60, 4.0/3.0, 0.1, 20.0);
            mCamera->lookAt(QVector3D{0, 0, z_Axis}, QVector3D{x_Axis,0,0}, QVector3D{0,1,0});
            glUniformMatrix4fv(mVmatrixUniform, 1, GL_TRUE, mCamera->mVmatrix.constData());
            glUniformMatrix4fv(mPmatrixUniform, 1, GL_TRUE, mCamera->mPmatrix.constData());
            mCamera->update();
        }
        if(Scene2){
            mCamera->perspective(90, 4.0/3.0, 0.1, 20.0);
            mCamera->lookAt(QVector3D{0, 0, 1.8f}, QVector3D{0,0,0}, QVector3D{0,1,0});
            glUniformMatrix4fv(mVmatrixUniform, 1, GL_TRUE, mCamera->mVmatrix.constData());
            glUniformMatrix4fv(mPmatrixUniform, 1, GL_TRUE, mCamera->mPmatrix.constData());
            mCamera->update();
        }

        glUseProgram(mShaderProgram[0]->getProgram());

        //LIGHTSOURCE
        for (auto LS_nr = LightSourceList.begin(); LS_nr != LightSourceList.end(); ++LS_nr)
        {
            glUniform3f(mLightPosition, LightSourceObject->Coordinate_X, LightSourceObject->Coordinate_Y, LightSourceObject->Coordinate_Z);
            glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, (*LS_nr)->mMatrix.constData());
            (*LS_nr)->draw();
        }


        glUseProgram( mShaderProgram[2]->getProgram());
        //glUniform1f(mAmbientStrength, LightSourceObject->AmbientLightStrength);
        // mOBJECTS VECTOR STUFF
       for (auto it=mObjects.begin(); it != mObjects.end(); it++)
       {
           glUniform3f(mObjectColour, (*it)->GetColour().x(), (*it)->GetColour().y(), (*it)->GetColour().z());

           glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, LightSourceObject->mMatrix.constData());

            //glUniform3f(mLightColour, LightSourceObject->LightColour.x(), LightSourceObject->LightColour.y(), LightSourceObject->LightColour.z());
            glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, (*it)->mMatrix.constData());
            (*it)->draw();
       }

        // WALKER
       for (auto it = npclist.begin(); it != npclist.end(); it++)
        {
            glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, LightSourceObject->mMatrix.constData());

            glUniform3f(mObjectColour, (*it)->GetColour().x(), (*it)->GetColour().y(), (*it)->GetColour().z());

            //glUniform1f(mAmbientStrength, LightSourceObject->AmbientLightStrength);
            //glUniform3f(mLightColour, LightSourceObject->LightColour.x(), LightSourceObject->LightColour.y(), LightSourceObject->LightColour.z());
            glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, (*it)->mMatrix.constData());
           (*it)->draw();
        }

       // TROPHIES
        for (auto trophy_nr = trophyList.begin(); trophy_nr < trophyList.end(); ++trophy_nr)
        {
            //(*trophy_nr)->draw();
            if (Player->checkPlayerPresence == true && Scene1 == true && (*trophy_nr)->DidItemGetPickedUp == false )
            {
                bool CollectionDetection = CollisionDetection(Player, (*trophy_nr));

                if (!CollectionDetection)
                {
                    //std::cout << "collectiondetection is true, we picked up a trophy\n";
                    glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, LightSourceObject->mMatrix.constData());

                    glUniform3f(mObjectColour,  (*trophy_nr)->GetColour().x(),  (*trophy_nr)->GetColour().y(),  (*trophy_nr)->GetColour().z());


                    //glUniform1f(mAmbientStrength, LightSourceObject->AmbientLightStrength);
                    //glUniform3f(mLightColour, LightSourceObject->LightColour.x(), LightSourceObject->LightColour.y(), LightSourceObject->LightColour.z());
                    glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, (*trophy_nr)->mMatrix.constData());
                    (*trophy_nr)->draw();
                    (*trophy_nr)->DidItemGetPickedUp = true;
                }
                else if (CollectionDetection)
                {
                    //std::cout << "collectiondetection is false, we didn't pick up anything\n";
                    glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, LightSourceObject->mMatrix.constData());


//                    glUniform1f(mAmbientStrength, LightSourceObject->AmbientLightStrength);
//                    glUniform3f(mLightColour, LightSourceObject->LightColour.x(), LightSourceObject->LightColour.y(), LightSourceObject->LightColour.z());
                    glUniform3f(mObjectColour,  (*trophy_nr)->GetColour().x(),  (*trophy_nr)->GetColour().y(),  (*trophy_nr)->GetColour().z());
                    glUniformMatrix4fv(mMmatrixUniform, 1, GL_TRUE, (*trophy_nr)->mMatrix.constData());
                    (*trophy_nr)->draw();
                    //(*trophy_nr)->DidItemGetPickedUp = true;
                }
            }
            else if (Player->checkPlayerPresence == true && Scene1 == true && (*trophy_nr)->DidItemGetPickedUp == true)
            {
                // trophy is already picked up
            }

        }
    }

    //glUniformMatrix4fv(mAmbientStrength, 1, GL_TRUE, LightSourceObject->AmbientLightStrength);


    // Mo/Joakim
    // Joakim test 07.04.23
    // Test to see if I can change the height (y) in render
    // or if I need to implement a setHeight function
    if ((px >= 1.0f) && (pz >= 1.0f) && (px <= 255.0f) && (pz <= 255.0f))
    {
        // Snap player to floor
        float y = barrysentricHeightOfPlayer() + 1.0f;
        Player->Coordinate_Y = y;
    }
    else
    {
        // When out of bounds of heightmap, snap to 0. height
        Player->Coordinate_Y = 0.0f;
    }
    // Har ikkje testet enda, as of 09:00




    calculateFramerate();
    checkForGLerrors(); //using our expanded OpenGL debugger to check if everything is OK.
    mContext->swapBuffers(this);
}

//This function is called from Qt when window is exposed (shown)
// and when it is resized
//exposeEvent is a overridden function from QWindow that we inherit from
void RenderWindow::exposeEvent(QExposeEvent *)
{
    //if not already initialized - run init() function - happens on program start up
    if (!mInitialized)
        init();

    //This is just to support modern screens with "double" pixels (Macs and some 4k Windows laptops)
    const qreal retinaScale = devicePixelRatio();

    //Set viewport width and height to the size of the QWindow we have set up for OpenGL
    glViewport(0, 0, static_cast<GLint>(width() * retinaScale), static_cast<GLint>(height() * retinaScale));

    //If the window actually is exposed to the screen we start the main loop
    //isExposed() is a function in QWindow
    if (isExposed())
    {
        //This timer runs the actual MainLoop
        //16 means 16ms = 60 Frames pr second (should be 16.6666666 to be exact...)
        mRenderTimer->start(16);
        mTimeStart.start();
    }
}

//The way this function is set up is that we start the clock before doing the draw call,
// and check the time right after it is finished (done in the render function)
//This will approximate what framerate we COULD have.
//The actual frame rate on your monitor is limited by the vsync and is probably 60Hz
void RenderWindow::calculateFramerate()
{
    long nsecElapsed = mTimeStart.nsecsElapsed();
    static int frameCount{0};                       //counting actual frames for a quick "timer" for the statusbar

    if (mMainWindow)            //if no mainWindow, something is really wrong...
    {
        ++frameCount;
        if (frameCount > 30)    //once pr 30 frames = update the message == twice pr second (on a 60Hz monitor)
        {
            //showing some statistics in status bar
            mMainWindow->statusBar()->showMessage(" Time pr FrameDraw: " +
                                                  QString::number(nsecElapsed/1000000.f, 'g', 4) + " ms  |  " +
                                                  "FPS (approximated): " + QString::number(1E9 / nsecElapsed, 'g', 7));
            frameCount = 0;     //reset to show a new message in 30 frames
        }
    }
}

//Uses QOpenGLDebugLogger if this is present
//Reverts to glGetError() if not
void RenderWindow::checkForGLerrors()
{
    if(mOpenGLDebugLogger)  //if our machine got this class to work
    {
        const QList<QOpenGLDebugMessage> messages = mOpenGLDebugLogger->loggedMessages();
        for (const QOpenGLDebugMessage &message : messages)
        {
            if (!(message.type() == message.OtherType)) // get rid of uninteresting "object ...
                                                        // will use VIDEO memory as the source for
                                                        // buffer object operations"
                // valid error message:
                mLogger->logText(message.message().toStdString(), LogType::REALERROR);
        }
    }
    else
    {
        GLenum err = GL_NO_ERROR;
        while((err = glGetError()) != GL_NO_ERROR)
        {
            mLogger->logText("glGetError returns " + std::to_string(err), LogType::REALERROR);
            switch (err) {
            case 1280:
                mLogger->logText("GL_INVALID_ENUM - Given when an enumeration parameter is not a "
                                "legal enumeration for that function.");
                break;
            case 1281:
                mLogger->logText("GL_INVALID_VALUE - Given when a value parameter is not a legal "
                                "value for that function.");
                break;
            case 1282:
                mLogger->logText("GL_INVALID_OPERATION - Given when the set of state for a command "
                                "is not legal for the parameters given to that command. "
                                "It is also given for commands where combinations of parameters "
                                "define what the legal parameters are.");
                break;
            }
        }
    }
}

//Tries to start the extended OpenGL debugger that comes with Qt
//Usually works on Windows machines, but not on Mac...
void RenderWindow::startOpenGLDebugger()
{
    QOpenGLContext * temp = this->context();
    if (temp)
    {
        QSurfaceFormat format = temp->format();
        if (! format.testOption(QSurfaceFormat::DebugContext))
            mLogger->logText("This system can not use QOpenGLDebugLogger, so we revert to glGetError()",
                             LogType::HIGHLIGHT);

        if(temp->hasExtension(QByteArrayLiteral("GL_KHR_debug")))
        {
            mLogger->logText("This system can log extended OpenGL errors", LogType::HIGHLIGHT);
            mOpenGLDebugLogger = new QOpenGLDebugLogger(this);
            if (mOpenGLDebugLogger->initialize()) // initializes in the current context
                mLogger->logText("Started Qt OpenGL debug logger");
        }
    }
}

// Mo
bool RenderWindow::isItBottomTriangle(int posX, int posZ)
{
//    if (px > 0.0f && py > 0.0f && pz > 0.0f)
//    {
        // To check if we need to calculate the top or bottom triangle on a quad
        // QVector3D VertPos1 = *heightmap->GetSurfacePos(posX, posZ - 1);
        // QVector3D VertPos2 = *heightmap->GetSurfacePos(posX + 1, posZ - 1 + 1);
        // Now why the fuck does it have to be -1+1???? ^^
        // VertPos1.setY(0.0f);
        // VertPos2.setY(0.0f);

        // QVector3D DiagonalVector = VertPos2 - VertPos1;
        // QVector3D PlayerVector = QVector3D(px, 0, pz) - VertPos1;

//        PlayerVector.normalize(); // What does normalize do?

//        QVector3D Results = QVector3D::crossProduct(PlayerVector, DiagonalVector);

//        if (Results.y() > 0)
//        {
//            bIsBottomTriangle = true;
//            return true;
//        }
//        else
//        {
//            bIsBottomTriangle = false;
//            return false;
//        }
//    }
    return false; // Removes a warning
}

// Mo
float RenderWindow::barrysentricHeightOfPlayer()
{
//    // int casting
//    int x = static_cast<int>(px);   // Removes floating points
//    //int y = static_cast<int>(py);
//    int z = static_cast<int>(pz);
//    QVector3D VertPos1, VertPos2, VertPos3, Bary;
//    isItBottomTriangle(x, z);

//    if (px > 0.0f && pz > 0.0f)
//    {
//        // 1st triangle in quad
//        if (bIsBottomTriangle)
//        {
//            // Get vertex pos of surface and turn it into 2D vector
//            VertPos1 = *heightmap->GetSurfacePos(x, z - 1);
//            VertPos2 = *heightmap->GetSurfacePos(x + 1, z - 1);
//            VertPos3 = *heightmap->GetSurfacePos(x + 1, z);
//            // Again, why -1 + 1???

//            // Calculate barycentric
//            Bary = BarysentricCoordinates(VertPos1, VertPos2, VertPos3);
//        }

//        // 2nd
//        else if (!bIsBottomTriangle)
//        {
//            VertPos1 = *heightmap->GetSurfacePos(x + 1, z - 1 + 1);
//            VertPos2 = *heightmap->GetSurfacePos(x, z);
//            VertPos3 = *heightmap->GetSurfacePos(x, z - 1);
//            Bary = BarysentricCoordinates(VertPos1, VertPos2, VertPos3);
//        }
//        // Sum
//        return VertPos1.y()*Bary.x() + VertPos2.y()*Bary.y() + VertPos3.y()*Bary.z();
//    }
    return 0.0f; // Return to ground
}

// Mo/Joakim  vi tar begge fra kompendiumet i matte
QVector3D RenderWindow::BarysentricCoordinates(QVector3D p1, QVector3D p2, QVector3D p3)
{
//    // Set height to zero
//    p1.setY(0.0f);
//    p2.setY(0.0f);
//    p3.setY(0.0f);

//    // Math3 compendium, page 83 (89 in pdf)


//    QVector3D p12 = p2 - p1;
//    QVector3D p13 = p3 - p1;

//    QVector3D n = QVector3D::crossProduct(p12, p13);
//    float area_123 = n.length();   // doubled area

    QVector3D baryc;    // For return. Gets filled with u,v,w

//    // u
//    QVector3D p = p2 - QVector3D(px, 0.0f, pz);
//    QVector3D q = p3 - QVector3D(px, 0.0, pz);
//    n = QVector3D::crossProduct(p, q);
//    baryc.setX(n.y()/area_123);

//    // v
//    p = p3 - QVector3D(px, 0.0f, pz);
//    q = p1 - QVector3D(px, 0.0f, pz);
//    n = QVector3D::crossProduct(p, q);
//    baryc.setY(n.y()/area_123);

//    // w
//    p = p1 - QVector3D(px, 0.0f, pz);
//    q = p2 - QVector3D(px, 0.0f, pz);
//    n = QVector3D::crossProduct(p, q);
//    baryc.setZ(n.y()/area_123);

    return -baryc; // Mo bruker -baryc  teste først og se
}

//Event sent from Qt when program receives a keyPress
// NB - see renderwindow.h for signatures on keyRelease and mouse input
void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    //Player1
    {
    //Forward
    if (event->key() == Qt::Key_W)
    {
       Player->move(0.0f, 0.0f, -0.1f);       //Moves forward
       z_Axis += -0.1f;
    }
    //Backward
    if (event->key() == Qt::Key_S)
    {
       Player->move(0.0f, 0.0f, 0.1f);       //Moves forward
       z_Axis += 0.1f;
    }
    //Right
    if (event->key() == Qt::Key_D)
    {
       Player->move(0.1f, 0.0f, 0.0f);       //Moves forward
       x_Axis += 0.1f;
    }
    //Left
    if (event->key() == Qt::Key_A)
    {
       Player->move(-0.1f, 0.0f, 0.0f);       //Moves forward
       x_Axis += -0.1f;
    }

    }


    if (event->key() == Qt::Key_Escape)
    {
        mMainWindow->close();       //Shuts down the whole program
    }

    // Draw Scene1
    if (event->key() == Qt::Key_1)
    {
        if(!Scene1){

        scene1_House->checkScene1 = true;
        scene1_House->checkScene2 = false;
        scene1_Door->checkScene1 = true;
        scene1_PressurePlate->checkScene1 = true;
        Player->checkScene1 = true;
        Scene1 = true;
        }
        else{
            scene1_House->checkScene1 = false;
            scene1_Door->checkScene1 = false;
            scene1_PressurePlate->checkScene1 = false;
            Player->checkScene1 = false;
            Scene1 = false;


        }
    }

    // Opening the door
    if (event->key() == Qt::Key_O)
    {

        if(!doorOpen){
        scene1_Door->setRotation(80, 0, 1, 0);
        scene1_Door->setPos(QVector3D{1.6, 0, -1.4});
        doorOpen = true;
        }
    }

    // Scene2
    if (event->key() == Qt::Key_2)
    {
        scene1_House->checkScene2 = true;
        scene1_Door->checkScene2 = true;
        ObjectInHouse->checkScene2 = true; // Test
        scene1_Door->checkScene1 = false;
        scene1_PressurePlate->checkScene1 = false;
        Player->checkScene1 = false;

        Scene1 = false;
        Scene2 = true;

        scene1_House->setPos(QVector3D{0, 0, 1});
        scene1_House->setRotation(45, 0, 1, 0);

        scene1_Door->setRotation(45, 0, 1, 0);
        scene1_Door->setPos(QVector3D{-0.6, 0, 2});

        scene1_PressurePlate->setPos(QVector3D{0, 0, 1});
        scene1_PressurePlate->setRotation(45, 0, 1, 0);

        ObjectInHouse->setRotation(45, 0, 1, 0);

        // Object in house
    }

    if (event->key() == Qt::Key_3)
    {
    if(Walker->b_showGraph_2 == false){
        Walker->b_showGraph_2 = true;
    }
    else
    {
        Walker->b_showGraph_2 = false;
    }
    }
}
