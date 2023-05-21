#include "graphobj.h"

GraphObj::GraphObj(){

}

GraphObj::~GraphObj(){
    delete this;
}

QPoint GraphObj::getStopPoint() const
{
    return stopPoint;
}

void GraphObj::setStopPoint(QPoint newStopPoint)
{
    stopPoint = newStopPoint;
}

QPoint GraphObj::getStartPoint() const
{
    return startPoint;
}

void GraphObj::setStartPoint(QPoint newStartPoint)
{
    startPoint = newStartPoint;
}

bool GraphObj::getOutline() const{
    return outline;
}

void GraphObj::setOutline(bool newOutline){
    outline = newOutline;
}

QColor GraphObj::getColor() const
{
    return color;
}

void GraphObj::setColor(const QColor &newColor)
{
    color = newColor;
}

void GraphObj::setBrushForTheObject(QPainter &painter)
{
    // Set brush color using hexadecimal value
    painter.setPen(getColor());
    if(!getOutline()){
        painter.setBrush(Qt::NoBrush);
    }else{
        painter.setBrush(getColor());
    }

}


