#ifndef LINE_H
#define LINE_H

#include "graphobj.h"

#define RANGE 50

class Line : public GraphObj{

public:
    Line();
    virtual ~Line();
    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint p);
    float getSteigung();
    float getConstanteB();



};

#endif // LINE_H
