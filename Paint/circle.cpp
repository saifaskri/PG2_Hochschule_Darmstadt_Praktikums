#include "circle.h"
#include <iostream>

Circle::Circle(){
    diameter = std::sqrt( (getStartPoint().x()-getStopPoint().x()) * (getStartPoint().x()-getStopPoint().x()) +  (getStartPoint().y()-getStopPoint().y()) * (getStartPoint().y()-getStopPoint().y()) );
}

Circle::~Circle(){

}

void Circle::draw(QPainter &painter){

    // change later if i will work with new
    diameter = std::sqrt( (getStartPoint().x()-getStopPoint().x()) * (getStartPoint().x()-getStopPoint().x()) +  (getStartPoint().y()-getStopPoint().y()) * (getStartPoint().y()-getStopPoint().y()) );

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);

    painter.drawEllipse(getStartPoint(), diameter,diameter);

}

bool Circle::checkTheSelectedShape(QPoint p){

    int distancePointToCenter = std::sqrt( (getStartPoint().x() - p.x()) *
                                           (getStartPoint().x() - p.x()) +
                                           (getStartPoint().y() - p.y()) *
                                           (getStartPoint().y() - p.y()) );

    if( diameter > distancePointToCenter ){
       std::cout<<"Object is selected"<<std::endl;
       return true;
    }

    return false;
}

int Circle::getDiameter() const{
    return diameter;
}

void Circle::setDiameter(int newDiameter){
    diameter = newDiameter;
}
