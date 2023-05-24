#ifndef LINE_H
#define LINE_H

#include "graphobj.h"
#define RANGE 40
class Line : public GraphObj{

public:
    Line();
    virtual ~Line();
    void draw(QPainter &painter);
    bool checkTheSelectedShape(QPoint p);
    float getSteigung();
    float getConstanteB();



};

#endif // LINE_H
