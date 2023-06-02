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

    QPoint vector;
    for(koordinate *k : pointHestory) {

        vector = p - k->startPoint ;

         if ( RANGEs > sqrt( (vector.x()*vector.x()) + (vector.y()*vector.y()) )   ){
             return true;
        }

    }

    return false;


}


