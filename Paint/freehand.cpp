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

void FreeHand::drawBBox(QPainter &painter){

//    int Ymin = pointHestory[0]->startPoint.y();
//    int Ymax = pointHestory[0]->startPoint.y();
//    int Xmin = pointHestory[0]->startPoint.x();
//    int Xmax = pointHestory[0]->startPoint.x();

//    for(auto pt : pointHestory){

//        if( pt->stopPoint.y() > Ymax ){
//          Ymax = pt->stopPoint.y();
//        }

//        if( pt->stopPoint.y() < Ymin ){
//          Ymin = pt->stopPoint.y();
//        }

//        if( pt->stopPoint.x() > Xmax ){
//          Xmax = pt->stopPoint.x();
//        }

//        if( pt->stopPoint.x() < Xmin ){
//          Xmin = pt->stopPoint.x();
//        }
//    }

//    QPoint startpoint;
//    startpoint.setX(Xmin);
//    startpoint.setY(Ymin);

//    QPoint stopPoint;
//    stopPoint.setX(Xmax);
//    stopPoint.setY(Ymax);

//    // change later if i will work with new
//    int width =   (stopPoint.x() - startpoint.x()) ;
//    int height =  (stopPoint.y() - startpoint.y())  ;
//    // Set brush color using hexadecimal value
//    painter.setPen(QPen(Qt::red, BboxSize , Qt::DashLine));
//    painter.setBrush(Qt::NoBrush);
//    painter.drawRect(startpoint.x(),startpoint.y(), width, height);



}

void FreeHand::calcBBox(QPoint &min, QPoint &max) const{

    int Ymin = pointHestory[0]->startPoint.y();
    int Ymax = pointHestory[0]->startPoint.y();
    int Xmin = pointHestory[0]->startPoint.x();
    int Xmax = pointHestory[0]->startPoint.x();

    for(auto pt : pointHestory){

        if( pt->stopPoint.y() > Ymax ){
          Ymax = pt->stopPoint.y();
        }

        if( pt->stopPoint.y() < Ymin ){
          Ymin = pt->stopPoint.y();
        }

        if( pt->stopPoint.x() > Xmax ){
          Xmax = pt->stopPoint.x();
        }

        if( pt->stopPoint.x() < Xmin ){
          Xmin = pt->stopPoint.x();
        }
    }

    min.setX(Xmin);
    min.setY(Ymin);

    max.setX(Xmax);
    max.setY(Ymax);


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


