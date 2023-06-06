#include "line.h"

Line::Line()
{

}

void Line::draw(QPainter &p){

    GraphObject::draw(p);

    p.drawLine(getStartPoint(),getStopPoint());

}

bool Line::selected(QPoint p)
{
    return false;
}
