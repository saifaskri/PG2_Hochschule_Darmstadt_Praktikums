#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H


#include "graphobj.h"

class BBoxDecorator :public GraphObj {

private:
    QPoint min;
    QPoint max;

public:
    BBoxDecorator();
    BBoxDecorator(GraphObj* o);
    ~BBoxDecorator();
    void calcBBox(QPoint &min, QPoint &max) const ;

     bool drawingIsDone();
     void drawBBox(QPainter &painter);
     void draw(QPainter &painter) ;
     void move(QPoint vector) ;
     bool checkTheSelectedShape(QPoint p);
     GraphObj* wrappee;

};

#endif // BBOXDECORATOR_H
