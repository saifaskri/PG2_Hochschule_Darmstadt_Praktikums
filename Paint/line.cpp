#include "line.h"
#include <iostream>


Line::Line(){

}

Line::~Line(){

}

void Line::draw(QPainter &painter){

    painter.setPen(QPen(getColor(), 2 , Qt::SolidLine));
    painter.drawLine(getStartPoint(), getStopPoint());

}

bool Line::checkTheSelectedShape(QPoint){

    return false;
}

