#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "graphobj.h"


class Triangle : public GraphObj{

public:
    Triangle();
    virtual ~Triangle();
    void draw(QPainter &painter);
};

#endif // TRIANGLE_H
