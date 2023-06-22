#include "bboxdecorator.h"
#include <iostream>
#include <ostream>

BBoxDecorator::BBoxDecorator()
{

}

BBoxDecorator::BBoxDecorator(GraphObj *o):wrappee(o){

}

BBoxDecorator::~BBoxDecorator()
{

}

void BBoxDecorator::calcBBox(QPoint &min, QPoint &max) const{
    wrappee->calcBBox(min,max);
}

bool BBoxDecorator::drawingIsDone(){

    wrappee->drawingIsDone();
}

void BBoxDecorator::drawBBox(QPainter &painter){

    wrappee->calcBBox(min,max);

    // change later if i will work with new
    int width =   (min.x() - max.x()) ;
    int height =  (min.y() - max.y())  ;
    // Set brush color using hexadecimal value
    painter.setPen(QPen(Qt::red, BboxSize , Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(max.x(),max.y(), width, height);


}

void BBoxDecorator::draw(QPainter &painter){
    wrappee->draw(painter);
}

void BBoxDecorator::move(QPoint vector){
    wrappee->move(vector);
}

bool BBoxDecorator::checkTheSelectedShape(QPoint p){
    wrappee->checkTheSelectedShape(p);
}
