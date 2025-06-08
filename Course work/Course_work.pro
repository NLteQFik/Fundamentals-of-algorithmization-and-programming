QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithmeditor.cpp \
    coloringsolver.cpp \
    connectivitysolver.cpp \
    edge.cpp \
    edgeeditor.cpp \
    euleriansolver.cpp \
    graph.cpp \
    isomorphismsolver.cpp \
    main.cpp \
    mainwindow.cpp \
    matchingsolver.cpp \
    maxflowsolver.cpp \
    mincostflowsolver.cpp \
    minspanningforestsolver.cpp \
    mygraphicsscene.cpp \
    myview.cpp \
    shortestpathsolver.cpp \
    vertex.cpp \
    vertexeditor.cpp

HEADERS += \
    algorithmeditor.h \
    coloringsolver.h \
    connectivitysolver.h \
    edge.h \
    edgeeditor.h \
    euleriansolver.h \
    graph.h \
    isomorphismsolver.h \
    mainwindow.h \
    matchingsolver.h \
    maxflowsolver.h \
    mincostflowsolver.h \
    minspanningforestsolver.h \
    mygraphicsscene.h \
    myview.h \
    shortestpathsolver.h \
    vertex.h \
    vertexeditor.h

FORMS += \
    algorithmeditor.ui \
    edgeeditor.ui \
    mainwindow.ui \
    myview.ui \
    vertexeditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
