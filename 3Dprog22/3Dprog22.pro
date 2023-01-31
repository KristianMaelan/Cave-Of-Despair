QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    cube.cpp \
    logger.cpp \
    mainwindow.cpp \
    renderwindow.cpp \
    shader.cpp \
    trianglesurface.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    cube.h \
    logger.h \
    mainwindow.h \
    renderwindow.h \
    shader.h \
    trianglesurface.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    plainshader.frag \
    plainshader.vert
