#include "circle.h"

Circle::Circle()
{

}


void Circle::draw(QPainter &p){

    QPoint vector = getStopPoint() - getStartPoint();
    radius = sqrt((vector.x() * vector.x()) + (vector.y() * vector.y())) ;


    GraphObject::draw(p);

    p.drawEllipse(getStartPoint() , radius, radius);

}

bool Circle::selected(QPoint p)
{
    QPoint clickedVector = p - getStartPoint();

    int clickedVectorBetrag = sqrt((clickedVector.x() * clickedVector.x()) + (clickedVector.y() * clickedVector.y())) ;

    return (radius >= clickedVectorBetrag) ;

}


int Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(int newRadius)
{
    radius = newRadius;
}
