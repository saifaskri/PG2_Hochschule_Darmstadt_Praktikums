#include "rectangle.h"

Rectangle::Rectangle(){
    width =   getStopPoint().x() - getStartPoint().x() ;
    height =  getStopPoint().y() - getStartPoint().y()  ;
}

Rectangle::~Rectangle(){

}

void Rectangle::draw(QPainter &painter){


    // change later if i will work with new
    width =   getStopPoint().x() - getStartPoint().x() ;
    height =  getStopPoint().y() - getStartPoint().y()  ;

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);

    painter.drawRect(getStartPoint().x(),getStartPoint().y(), width, height);

}

bool Rectangle::checkTheSelectedShape(QPoint)
{

    return false;
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
