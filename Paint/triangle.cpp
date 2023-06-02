#include "triangle.h"

Triangle::Triangle(){

}

Triangle::~Triangle(){

}

void Triangle::draw(QPainter &painter){

    Line *l = new Line();
    l->setStartPoint(getStartPoint());
    l->setStopPoint(getStopPoint());
    l->setColor(getColor());
    l->setOutline(getOutline());

    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);
    painter.drawLine(getStartPoint(), getStopPoint());
    lineList.push_back(l);


}

bool Triangle::checkTheSelectedShape(QPoint p)
{
    return false;
}

bool Triangle::getDone() const
{
    return done;
}

void Triangle::setDone(bool newDone)
{
    done = newDone;
}
