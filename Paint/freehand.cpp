#include "freehand.h"
#include <iostream>

FreeHand::FreeHand(){
}

FreeHand::FreeHand(const FreeHand &graph){

    this->setStartPoint(graph.getStartPoint());
    this->setStopPoint( graph.getStopPoint());
    this->setColor(graph.getColor());
    this->setOutline(graph.getOutline());

    for (int i = 0; (size_t)i < pointHestory.size(); ++i){
        koordinate *k = new koordinate(pointHestory[i]->startPoint,
                                       pointHestory[i]->stopPoint);
        this->pointHestory.push_back(k);
    }

}

FreeHand &FreeHand::operator=(const FreeHand &graph)
{
    this->setStartPoint(graph.getStartPoint());
    this->setStopPoint( graph.getStopPoint());
    this->setColor(graph.getColor());
    this->setOutline(graph.getOutline());

    // check if the Operation is a = a then do nothing ;
    //but a = b ; is okey
    if (this != &graph) {
        for (int i = 0; (size_t)i < pointHestory.size(); ++i){
            koordinate *k = new koordinate(graph.pointHestory[i]->startPoint,
                                           graph.pointHestory[i]->stopPoint);
            this->pointHestory.push_back(k);

        }

    }

    return *this;
}

FreeHand::~FreeHand(){
}

void FreeHand::draw(QPainter &painter){
    // Set brush color using hexadecimal value
    setBrushForTheObject(painter);
    for (size_t i = 0; i < pointHestory.size(); ++i) {
        painter.drawLine(pointHestory[i]->startPoint,pointHestory[i]->stopPoint);

    }
}

void FreeHand::move(QPoint vector){
    for(auto eachpoint : pointHestory){
        eachpoint->startPoint+=vector;
        eachpoint->stopPoint+=vector;
    }
}

bool FreeHand::checkTheSelectedShape(QPoint p){
    QPoint vector;
    for(koordinate *k : pointHestory) {
        vector = p - k->startPoint ;
         if ( RANGEs > sqrt( (vector.x()*vector.x()) + (vector.y()*vector.y()) )   ){
             return true;
        }
    }
    return false;
}


