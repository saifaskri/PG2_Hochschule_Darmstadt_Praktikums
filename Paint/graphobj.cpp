#include "graphobj.h"

GraphObj::GraphObj(){

}

GraphObj::GraphObj(const GraphObj &graph)
{
    this->startPoint =  graph.startPoint ;
    this->stopPoint =  graph.stopPoint ;
    this->color = graph.color ;
    this->outline = graph.outline ;
}

//GraphObj &GraphObj::operator=(const GraphObj &graph) const
//{
////    if(*this != graph ){

////    }
////    return this;
//}

GraphObj::~GraphObj(){

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

    painter.setPen(QPen(getColor(), FONTSIZE , Qt::SolidLine));

    if(!getOutline()){
        painter.setBrush(Qt::NoBrush);
    }else{
        painter.setBrush(getColor());
    }


}



