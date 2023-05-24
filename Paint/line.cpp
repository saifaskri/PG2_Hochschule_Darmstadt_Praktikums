#include "line.h"
#include <iostream>


Line::Line(){

}

Line::~Line(){

}

void Line::draw(QPainter &painter){

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);


    painter.setPen(QPen(getColor(), 1 , Qt::SolidLine));

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


    float a = getSteigung();
    float b = getConstanteB() ;

//    std::cout<<"StartPoint"<<"( "<<getStartPoint().x()<<" , "<<getStartPoint().y()<<" ) "<<std::endl;
//    std::cout<<"StopPoint"<<"( "<<getStopPoint().x()<<" , "<<getStopPoint().y()<<" ) "<<std::endl;
//    std::cout<<"p "<<"( "<<p.x()<<" , "<<p.y()<<" ) "<<std::endl;
//    std::cout<<"Gleichung "<<a<<" (x) + "<<b<<std::endl;
//    std::cout<<std::endl<<std::endl;


    float res = a * p.x() + b - p.y() ;
    //std::cout<<a * p.x() + b<<" = (py)  "<<p.y()<<std::endl;


    if(getStartPoint().y() > getStopPoint().y()){
        QPoint y;
        y = getStopPoint();
        setStopPoint(getStartPoint());
        setStartPoint(y);
    }


    if(  ( getStartPoint().y() < p.y() &&  getStopPoint().y() > p.y() ) && ( res<RANGE && res> - RANGE) ){
        std::cout<<"Object is selected"<<std::endl;
        return true;
    }




    return false;
}

