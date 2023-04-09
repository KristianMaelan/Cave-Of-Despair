QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    camera.cpp \
    cube.cpp \
    door.cpp \
    grapher.cpp \
    house.cpp \
    interaction.cpp \
    lightsource.cpp \
    logger.cpp \
    mainwindow.cpp \
    npc_grapher.cpp \
    player1.cpp \
    pressureplate.cpp \
    renderwindow.cpp \
    scene1_plan.cpp \
    shader.cpp \
    texture.cpp \
    trianglesurface.cpp \
    trophy.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    camera.h \
    cube.h \
    door.h \
    grapher.h \
    house.h \
    interaction.h \
    lightsource.h \
    logger.h \
    mainwindow.h \
    npc_grapher.h \
    player1.h \
    pressureplate.h \
    renderwindow.h \
    scene1_plan.h \
    shader.h \
    texture.h \
    trianglesurface.h \
    trophy.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    phongshader.frag \
    phongshader.vert \
    plainshader.frag \
    plainshader.vert \
    textureshader.frag \
    textureshader.vert \
    tempReadMeFile
