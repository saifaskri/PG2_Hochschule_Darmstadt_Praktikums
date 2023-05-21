#ifndef LINE_H
#define LINE_H

#include "graphobj.h"

class Line : public GraphObj{

public:
    Line();
    virtual ~Line();
    void draw(QPainter &painter);
    bool checkTheSelectedShape(QPoint);


};

#endif // LINE_H
