#ifndef LINE_H
#define LINE_H


#include "graphobject.h"

class Line : public GraphObject
{
public:
    Line();
    void draw(QPainter &p);
    bool selected(QPoint p);

};

#endif // LINE_H
