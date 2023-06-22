#include "line.h"
#include "rectangle.h"
#include <iostream>


Line::Line(){
     r = new Rectangle();

}

Line::Line(const Line &graph){
    this->setStartPoint(graph.getStartPoint());
    this->setStopPoint( graph.getStopPoint());
    this->setColor(graph.getColor());
    this->setOutline(graph.getOutline());
}

Line &Line::operator=(const Line &graph){

return *this;

}



Line::~Line(){

}

void Line::drawBBox(QPainter &painter){

    // change later if i will work with new
    int width =   (getStopPoint().x() - getStartPoint().x()) ;
    int height =  (getStopPoint().y() - getStartPoint().y())  ;
    // Set brush color using hexadecimal value
    painter.setPen(QPen(Qt::red, BboxSize , Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(getStartPoint().x(),getStartPoint().y(), width, height);

}

void Line::calcBBox(QPoint &min, QPoint &max) const{

    min = getStopPoint();
    max = getStartPoint();

}

void Line::draw(QPainter &painter){





    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);
    painter.drawLine(getStartPoint(), getStopPoint());

}

void Line::move(QPoint vector){
    setStartPoint(getStartPoint() + vector);
    setStopPoint(getStopPoint() + vector);
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

bool Line::checkTheSelectedShape(QPoint clicked){

//    QPoint p = clicked;
//    // swap start- and stop point if stop grather than start point
//    if(getStartPoint().y() > getStopPoint().y()){
//        QPoint y;
//        y = getStopPoint();
//        setStopPoint(getStartPoint());
//        setStartPoint(y);
//    }

//    float a = getSteigung();
//    float b = getConstanteB() ;
//    float res = a * p.x() + b - p.y();

//    return( getStartPoint().y() < p.y() &&  getStopPoint().y() > p.y() ) && ( res<RANGE && res> - RANGE) ;




//          L(t)       V
// p---------------------->
//          |
//          |
//          R
//    t0= (R - P).v/|v|^2

    QPoint v = getStopPoint() - getStartPoint();
    QPoint v_RP = clicked  - getStartPoint();
    //streckungsFaktor
    float t = (float)(v_RP.x() * v.x() + v_RP.y() * v.y() ) / (sqrt(v.x()*v.x() + v.y() *v.y()) * sqrt(v.x()*v.x() + v.y() *v.y())) ;
    // init lt and the cordonation of the POint must be positive abs() solve that problem
    QPoint lt ; lt.setX((t * v.x()));  lt.setY((t * v.y()));

    lt = lt + getStartPoint();

    std::cout<<" lt point "<<lt.x()<<" , "<<lt.y()<<std::endl;

    // Vector Senkrecht zu der Line v = RL(t)
    QPoint clicked_vector =   lt - clicked ;

    std::cout<<"clicked vector "<<clicked_vector.x()<<" , "<<clicked_vector.y()<<std::endl;


    std::cout<<"Betrag "<<sqrt(clicked_vector.x()*clicked_vector.x() + clicked_vector.y() * clicked_vector.y())<<std::endl;


    return ( t<=1 && t>=0  && RANGE >= sqrt( clicked_vector.x() * clicked_vector.x() + clicked_vector.y() * clicked_vector.y() )  );





}

