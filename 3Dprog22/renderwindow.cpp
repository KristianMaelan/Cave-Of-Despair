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

#include "shader.h"
#include "mainwindow.h"
#include "logger.h"
#include "xyz.h"
#include "trianglesurface.h"
<<<<<<< Updated upstream
#include "house.h"
#include "scene1_plan.h"
#include "pressureplate.h"
=======
#include "trophy.h"
>>>>>>> Stashed changes

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

    //Make the gameloop timer:
    mRenderTimer = new QTimer(this);

    mObjects.push_back(new XYZ());
   //mObjects.push_back(new TriangleSurface());

    // interaction with object
    // mObjects.push_back(new Interaction());
    // InteractiveObject = new Interaction;
    // mObjects.push_back(InteractiveObject);

    // Askelad-cube
    Comp1Cube = new Cube(0.5,0.5,0.5,1,0.5,0.5);
    mObjects.push_back(Comp1Cube);
    // Comp1Cube = new Cube;
    // mObjects.push_back(new Cube(0.5,0.5,0.5,1,0.5,0.5));

    // from tempReadMe, needs to be changed depending
    KristianGraf = new TriangleSurface("../3Dprog22/info.txt");
    mObjects.push_back(KristianGraf);

<<<<<<< Updated upstream
    // Oblig2 - Scene1_House
    scene1_House = new house(1, 1, 1, 0, 0, 0); // Create with dimensions
    scene1_House->setPos(QVector3D{0, 0, 0});   // Set position
    mObjects.push_back(scene1_House);

    // Oblig2 - Scene1_PressurePlate dimensions
    scene1_PressurePlate = new PressurePlate(1, 1, 1, 1, 0, 0);
    mObjects.push_back(scene1_PressurePlate);

    // Oblig2 - Scene1_Plan
    scene1_Plan = new Scene1_plan();
    mObjects.push_back(scene1_Plan);
=======
    // programming 2 - (1) IS IT POSSIBLE TO PUT IN A FOR LOOP TO MAKE SEVERAL CUBES? YES, BUT NEED CAMERA TO SEE WHAT IT REALLY LOOKS LIKE, BECAUSE THE SCREEN IS YELLOW
    double trophyX = 0.2;
    double trophyY = 0.2;
    double trophyZ = 0.2;

    //for (int i = 0; i < 7; ++i)
    //{
        trophyCube = new Trophy(trophyX, trophyY, trophyZ);
        trophyList.push_back(trophyCube);
     // mObjects.push_back(trophyCube);
      //  trophyX += 0.5f;
      //  trophyY += 0.5f;
      //  trophyZ += 0.5f;
       std::cout << "we have new trophies\n";
    //}
>>>>>>> Stashed changes
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
    mShaderProgram = new Shader("../3Dprog22/plainshader.vert", "../3Dprog22/plainshader.frag");


    // Get the matrixUniform location from the shader
    // This has to match the "matrix" variable name in the vertex shader
    // The uniform is used in the render() function to send the model matrix to the shader
    mPmatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "pMatrix" );
    mVmatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "vMatrix" );
    mMatrixUniform = glGetUniformLocation( mShaderProgram->getProgram(), "matrix" );

    mCamera.init(mPmatrixUniform, mVmatrixUniform);

    // mCamera.init(mPmatrixUniform, mVmatrixUniform);

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
        (*it)->init(mMatrixUniform);
    }
    for (auto trophy_nr = trophyList.begin(); trophy_nr < trophyList.end(); ++trophy_nr)
    {
        (*trophy_nr)->init(mMatrixUniform);
        std::cout << "mMatrixUnifrom is initialised\n";
    }
    glBindVertexArray(0);       //unbinds any VertexArray - good practice
}

bool RenderWindow::CollisionDetection(VisualObject *Player_ToRender, VisualObject *Obj_toRender)
{
    bool CollidedWith_X = Player_ToRender->Coordinate_X + 0.5 >= Obj_toRender->Coordinate_X && Obj_toRender->Coordinate_X + 0.5 >= Player_ToRender->Coordinate_X;
    bool CollidedWith_Y = Player_ToRender->Coordinate_Y + 0.5 >= Obj_toRender->Coordinate_Y && Obj_toRender->Coordinate_Y + 0.5 >= Player_ToRender->Coordinate_Y;

    return CollidedWith_X && CollidedWith_Y;
}

// Called each frame - doing the rendering!!!
void RenderWindow::render()
{
    mCamera.init(mPmatrixUniform, mVmatrixUniform);
    mCamera.perspective(60, 4.0/3.0, 0.1, 20.0);

    mTimeStart.restart(); //restart FPS clock
    mContext->makeCurrent(this); //must be called every frame (every time mContext->swapBuffers is called)

    initializeOpenGLFunctions();    //must call this every frame it seems...

    // Leksjon 3
    // mPmatrix->setToIdentity();
    // mVmatrix->setToIdentity();
    // mPmatrix->perspective(60, 4.0/3.0, 0.1, 10.0);


    //clear the screen for each redraw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //what shader to use
    glUseProgram(mShaderProgram->getProgram() );

    // Camera movement
    //float x = 15;
    mCamera.translate(0, 0, 15);
    mCamera.lookAt(QVector3D{0,0,5}, QVector3D{0,0,0}, QVector3D{0,1,0});
    mCamera.update();

    for (auto it=mObjects.begin(); it != mObjects.end(); it++)
    {
       (*it)->draw();
    }

    for (auto trophy_nr = trophyList.begin(); trophy_nr < trophyList.end(); ++trophy_nr) {
        if (!CollisionDetection(Comp1Cube, (*trophy_nr)))
        {
            (*trophy_nr)->draw();
        }
        else
        {
            (*trophy_nr)->DidItemGetPickedUp = true;
            (*trophy_nr)->mVAO = 0;
            (*trophy_nr)->mVBO = 0;
            std::cout << "Trophy was picked up!\n";
        }
    }

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

//Event sent from Qt when program receives a keyPress
// NB - see renderwindow.h for signatures on keyRelease and mouse input
void RenderWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        mMainWindow->close();       //Shuts down the whole program
    }

    // Draw Cube
    if (event->key() == Qt::Key_1)
    {
        Comp1Cube->checkCube = true;
    }

    // Draw Graph
    if (event->key() == Qt::Key_2)
    {
        KristianGraf->checkGraph = true;
    }

    // Draw xyz
    if (event->key() == Qt::Key_3)
    {

    }

    // Undraw Cube
    if (event->key() == Qt::Key_9)
    {
        Comp1Cube->checkCube = false;
    }

    // Draw Graph
    if (event->key() == Qt::Key_8)
    {
        KristianGraf->checkGraph = false;
    }

    // Draw Scene1
    if (event->key() == Qt::Key_Space)
    {
        scene1_House->checkScene1 = true;
    }
    // Undraw Scene1
    if (event->key() == Qt::Key_V)
    {
        scene1_House->checkScene1 = false;
    }

    // Moving InteractiveObject
    /*
    if (event->key() == Qt::Key_W && InteractiveObject)
    {
        InteractiveObject->move(0.f, 0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_S && InteractiveObject)
    {
        InteractiveObject->move(0.0f, -0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_A && InteractiveObject)
    {
        InteractiveObject->move(-0.1f, 0.f, 0.0f);
    }
    if (event->key() == Qt::Key_D && InteractiveObject)
    {
        InteractiveObject->move(0.1f, 0.0f, 0.0f);
    }
    */

    // Moving graph, not working
    /*
    if (event->key() == Qt::Key_W && KristianGraf)
    {
        KristianGraf->move(0.f, 0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_S && KristianGraf)
    {
        KristianGraf->move(0.0f, -0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_A && KristianGraf)
    {
        KristianGraf->move(-0.1f, 0.f, 0.0f);
    }
    if (event->key() == Qt::Key_D && KristianGraf)
    {
        KristianGraf->move(0.1f, 0.0f, 0.0f);
    }
    */
    // I want to know the Player's location

    // Moving Cube
    if (event->key() == Qt::Key_Up && Comp1Cube)
    {
        Comp1Cube->move(0.f, 0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_Down && Comp1Cube)
    {
        Comp1Cube->move(0.0f, -0.1f, 0.0f);
    }
    if (event->key() == Qt::Key_Left && Comp1Cube)
    {
        Comp1Cube->move(-0.1f, 0.f, 0.0f);
    }
    if (event->key() == Qt::Key_Right && Comp1Cube)
    {
        Comp1Cube->move(0.1f, 0.0f, 0.0f);
    }

    // Moving camera
    if (event->key() == Qt::Key_W)
    {
        qDebug() << "W pressed";
        //mCamera.lookAt(QVector3D{0,0,1}, QVector3D{0,0,0}, QVector3D{0,0,0});
        //mCamera.translate(10, 0, 0);
        //mCamera.update();
    }
    if (event->key() == Qt::Key_S)
    {

    }


}
