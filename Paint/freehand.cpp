#include "freehand.h"
#include <iostream>

FreeHand::FreeHand(){

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

bool FreeHand::checkTheSelectedShape(QPoint p){

//    for(koordinate *k : pointHestory) {
//        std::cout<<"Start Point: "<<" ( "<<k->startPoint.x()<<" , "<< k->startPoint.y()<<" ) "<<std::endl;
//        if(p.x() == k->startPoint.x()  && p.y() == k->startPoint.y() ){
//           std::cout<<"Object is selected"<<std::endl;
//           return true;
//        }
//    }

    return false;


}


