#include "circle.h"
#include <iostream>

Circle::Circle(){
    diameter = std::sqrt( (getStartPoint().x()-getStopPoint().x()) * (getStartPoint().x()-getStopPoint().x()) +  (getStartPoint().y()-getStopPoint().y()) * (getStartPoint().y()-getStopPoint().y()) );
}

Circle::Circle(const Circle &graph){
    this->setStartPoint(graph.getStartPoint());
    this->setStopPoint( graph.getStopPoint());
    this->setColor(graph.getColor());
    this->setOutline(graph.getOutline());
}

Circle &Circle::operator=(const Circle &graph){
    return *this;
}

void Circle::drawBBox(QPainter &painter){

    // change later if i will work with new
    int width =   this->diameter * 2 ;
    int height =  this->diameter * 2 ;

    // Set brush color using hexadecimal value
    painter.setPen(QPen(Qt::red, BboxSize , Qt::DashLine));
    painter.setBrush(Qt::NoBrush);

    painter.drawRect(getStartPoint().x()- diameter ,getStartPoint().y()- diameter , width, height);

}

void Circle::calcBBox(QPoint &min, QPoint &max) const{

    min.setX(getStartPoint().x()-diameter);
    min.setY(getStartPoint().y()-diameter);
    max.setX(getStartPoint().x()+diameter);
    max.setY(getStartPoint().y()+diameter);

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

void Circle::move(QPoint vector){
    setStartPoint(getStartPoint() + vector);
    setStopPoint(getStopPoint() + vector);
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
