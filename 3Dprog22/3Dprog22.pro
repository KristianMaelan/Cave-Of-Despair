QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    camera.cpp \
    cube.cpp \
    grapher.cpp \
    house.cpp \
    interaction.cpp \
    logger.cpp \
    mainwindow.cpp \
    renderwindow.cpp \
    scene1_plan.cpp \
    shader.cpp \
    trianglesurface.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    camera.h \
    cube.h \
    grapher.h \
    house.h \
    interaction.h \
    logger.h \
    mainwindow.h \
    renderwindow.h \
    scene1_plan.h \
    shader.h \
    trianglesurface.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    plainshader.frag \
    plainshader.vert \
    tempReadMeFile
