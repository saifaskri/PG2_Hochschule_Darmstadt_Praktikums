#ifndef LINE_H
#define LINE_H

#include "graphobj.h"
#include "rectangle.h"

#define RANGE 50

class Line : public GraphObj{

public:
    Line();
    Line(const Line& graph) ;
    Line& operator=(const Line& graph);
    virtual ~Line();

    void drawBBox(QPainter &painter);
    void calcBBox(QPoint &min, QPoint &max) const ;

    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint p);
    float getSteigung();
    float getConstanteB();
    Rectangle *r ;


};

#endif // LINE_H
