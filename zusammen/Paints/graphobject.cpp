#include "graphobject.h"
GraphObject::GraphObject()
{

}

void GraphObject::draw(QPainter &p)
{
    p.setPen(QPen(getColor(), 1 , Qt::SolidLine));

    if(getOutline()){
        p.setBrush(getColor());
    }else{
        p.setBrush(Qt::NoBrush);
    }

}

bool GraphObject::selected(QPoint p)
{
    return false;

}

QPoint GraphObject::getStartPoint() const
{
    return startPoint;
}

void GraphObject::setStartPoint(QPoint newStartPoint)
{
    startPoint = newStartPoint;
}

QPoint GraphObject::getStopPoint() const
{
    return stopPoint;
}

void GraphObject::setStopPoint(QPoint newStopPoint)
{
    stopPoint = newStopPoint;
}

QColor GraphObject::getColor() const
{
    return color;
}

void GraphObject::setColor(const QColor &newColor)
{
    color = newColor;
}

bool GraphObject::getOutline() const
{
    return outline;
}

void GraphObject::setOutline(bool newOutline)
{
    outline = newOutline;
}
