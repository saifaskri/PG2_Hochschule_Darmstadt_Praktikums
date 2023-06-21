#include "graphobj.h"
#include <iostream>
#include <ostream>

GraphObj::GraphObj(){

}

//GraphObj::GraphObj(const GraphObj &graph)
//{
//    this->startPoint =  graph.startPoint ;
//    this->stopPoint =  graph.stopPoint ;
//    this->color = graph.color ;
//    this->outline = graph.outline ;
//}

//GraphObj &GraphObj::operator=(const GraphObj &graph) {
//    // check if the Operation is a = a then do nothing ;
//    //but a = b ; is okey
//    if (this != &graph) {
//        // we dont need to do that because there are no pointer
//        this->startPoint =  graph.startPoint ;
//        this->stopPoint =  graph.stopPoint ;
//        this->color = graph.color ;
//        this->outline = graph.outline ;
//    }
//    return *this;

//}


GraphObj::~GraphObj(){

}

QPoint GraphObj::getStopPoint() const{
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

QColor GraphObj::getColor() const{
    return color;
}

void GraphObj::setColor(const QColor &newColor)
{
    color = newColor;
}

void GraphObj::setBrushForTheObject(QPainter &painter)
{
    // Set brush color using hexadecimal value

    painter.setPen(QPen(getColor(), FONTSIZE , penStyle));

    if(!getOutline()){
        painter.setBrush(Qt::NoBrush);
    }else{
        painter.setBrush(getColor());
    }


}

bool GraphObj::drawingIsDone(){
    std::cout<<"Drawing is done"<<std::endl;
    return true;
}

bool GraphObj::getDoneDrawing() const{
    return doneDrawing;
}

void GraphObj::setDoneDrawing(bool newDoneDrawing){
    doneDrawing = newDoneDrawing;
}

void GraphObj::setPenStyle(Qt::PenStyle newPenStyle)
{
    penStyle = newPenStyle;
}



