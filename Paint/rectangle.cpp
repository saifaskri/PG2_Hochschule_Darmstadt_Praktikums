#include "rectangle.h"
#include <iostream>
#include <ostream>

Rectangle::Rectangle(){
    width =   getStopPoint().x() - getStartPoint().x() ;
    height =  getStopPoint().y() - getStartPoint().y()  ;
}

Rectangle::Rectangle(const Rectangle &graph){
    this->setStartPoint(graph.getStartPoint());
    this->setStopPoint( graph.getStopPoint());
    this->setColor(graph.getColor());
    this->setOutline(graph.getOutline());
}

Rectangle &Rectangle::operator=(const Rectangle &graph)
{
    return *this;
}

Rectangle::~Rectangle(){

}

void Rectangle::drawBBox(QPainter &painter){
    // change later if i will work with new
    int width =   (getStopPoint().x() - getStartPoint().x()) ;
    int height =  (getStopPoint().y() - getStartPoint().y())  ;
    // Set brush color using hexadecimal value
    painter.setPen(QPen(Qt::red, BboxSize , Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(getStartPoint().x(),getStartPoint().y(), width, height);

}

void Rectangle::calcBBox(QPoint &min, QPoint &max) const{
    min = getStopPoint();
    max = getStartPoint();
}

void Rectangle::draw(QPainter &painter){


    // change later if i will work with new
    width =   getStopPoint().x() - getStartPoint().x() ;
    height =  getStopPoint().y() - getStartPoint().y()  ;

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);

    painter.drawRect(getStartPoint().x(),getStartPoint().y(), width, height);

}

void Rectangle::move(QPoint vector){
    setStartPoint(getStartPoint() + vector);
    setStopPoint(getStopPoint() + vector);
}

bool Rectangle::checkTheSelectedShape(QPoint p){

    // swap start- and stop point if stop grather than start point
      // swap start- and stop point if stop grather than start point

    if(getStartPoint().y() < getStopPoint().y()){
        QPoint y;
        y = getStopPoint();
        setStopPoint(getStartPoint());
        setStartPoint(y);
    }

    float steigung = (float)(getStartPoint().y() - getStopPoint().y())/(getStartPoint().x() - getStopPoint().x());

    // wenn Y nicht stimmt
    if(!(p.y() <= getStartPoint().y() &&   p.y() >= getStopPoint().y())) return false;

    // jenach Start- StopPunkt wird X anders geprüft mit Hilfe der Steigung der Diagonale
    if (steigung<0)
        return( p.x() >= getStartPoint().x() && p.x() <= getStopPoint().x() );
    else
        return(p.x() <= getStartPoint().x() &&p.x() >= getStopPoint().x() );
    
    // wenn Y nicht stimmt
    if(!(p.y() <= getStartPoint().y() &&   p.y() >= getStopPoint().y())) return false;
    
    // jenach Start- StopPunkt wird X anders geprüft mit Hilfe der Steigung der Diagonale
    if (steigung<0)
        return( p.x() >= getStartPoint().x() && p.x() <= getStopPoint().x() );         
    else
        return(p.x() <= getStartPoint().x() &&p.x() >= getStopPoint().x() );  

}



int Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(int newWidth)
{
    width = newWidth;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setHeight(int newHeight)
{
    height = newHeight;
}
