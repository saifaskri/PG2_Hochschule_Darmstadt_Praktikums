#include "triangle.h"
#include <iostream>
#include <ostream>

Triangle::Triangle(){

}

Triangle::Triangle(const Triangle &graph)
{

}

Triangle &Triangle::operator=(const Triangle &graph)
{
    return *this;
}

Triangle::~Triangle(){

}

// function for add in List ????????????????????????
void Triangle::draw(QPainter &painter){

    for(auto p :lineList){
       painter.drawLine(p->startPoint, p->stopPoint );
    }

    if(lineList.size()==0){
       painter.drawLine(getStartPoint(), getStopPoint());
    }else{
        painter.drawLine(lineList[0]->stopPoint, getStopPoint());
    }



}

bool Triangle::checkTheSelectedShape(QPoint p){
    return false;
}



void Triangle::move(QPoint vector){

}

bool Triangle::drawingIsDone(){
    if(lineList.size() == 2){
        std::cout<<"tri "<<lineList.size()<<" done "<<std::endl;

    }
    return ( lineList.size() == 2 );
}

bool Triangle::getDone() const
{
    return done;
}

void Triangle::setDone(bool newDone)
{
    done = newDone;
}

int Triangle::getNumberOfDrawedLine() const
{
    return numberOfDrawedLine;
}

void Triangle::setNumberOfDrawedLine(int newNumberOfDrawedLine)
{
    numberOfDrawedLine = newNumberOfDrawedLine;
}

bool Triangle::getReleasedClicked() const
{
    return releasedClicked;
}

void Triangle::setReleasedClicked(bool newReleasedClicked)
{
    releasedClicked = newReleasedClicked;
}
