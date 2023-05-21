# http://doc.qt.io/qt-5/qmake-variable-reference.html
CONFIG += console
QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
#LIBS += 
INCLUDEPATH += .

HEADERS += paint.h \
           canvas.h  \
           circle.h \
           freehand.h \
           graphobj.h \
           line.h \
           rectangle.h \
           triangle.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           freehand.cpp \
           graphobj.cpp \
           line.cpp \
           main.cpp \
           rectangle.cpp \
           triangle.cpp
