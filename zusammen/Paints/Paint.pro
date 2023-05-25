# http://doc.qt.io/qt-5/qmake-variable-reference.html
CONFIG += console
QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
#LIBS += 
INCLUDEPATH += .

HEADERS += paint.h \
           canvas.h  \
           circle.h \
           graphobject.h \
           line.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           graphobject.cpp \
           line.cpp \
           main.cpp
