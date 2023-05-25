#include "line.h"
#include <iostream>


Line::Line(){

}

Line::~Line(){

}

void Line::draw(QPainter &painter){

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);

    painter.drawLine(getStartPoint(), getStopPoint());

}

float Line::getSteigung(){

    float a = (float)(getStartPoint().y() - getStopPoint().y())/(getStartPoint().x() - getStopPoint().x());
    return a;
}

float Line::getConstanteB()
{
    float a = getSteigung();
    float b = getStartPoint().y() - a * getStartPoint().x() ;
    return b;
}

bool Line::checkTheSelectedShape(QPoint p){

    // swap start- and stop point if stop grather than start point
    if(getStartPoint().y() > getStopPoint().y()){
        QPoint y;
        y = getStopPoint();
        setStopPoint(getStartPoint());
        setStartPoint(y);
    }

    float a = getSteigung();
    float b = getConstanteB() ;
    float res = a * p.x() + b - p.y();

    return( getStartPoint().y() < p.y() &&  getStopPoint().y() > p.y() ) && ( res<RANGE && res> - RANGE);
}

