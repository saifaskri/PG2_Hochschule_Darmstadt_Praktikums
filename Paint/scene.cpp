#include "scene.h"
#include <iostream>
#include <ostream>

Scene::Scene(){

}

Scene::~Scene()
{
    for(int i = 0; i < (int)AllShape.size(); i++){
        delete AllShape[i];
    }
}

void Scene::draw(QPainter &painter)
{
    for(int i = 0; i < (int)AllShape.size(); i++){
        AllShape[i]->draw(painter);
    }

}

void Scene::deleteShape(QMouseEvent *event){

   int selectedIndex = selectObj(event) ;
   if(selectedIndex !=-1 ){
      AllShape.erase(AllShape.begin()+ selectedIndex );
    }

}

void Scene::AddShape(GraphObj *obj){
    AllShape.push_back(obj);
}

void Scene::DeleteAllShape(){
    AllShape.clear();
}

void Scene::moveShape(QPoint startPoint , QPoint endPoint){

    QPoint mouseClickedPoint = startPoint;
    QPoint mouseStopedPoint = endPoint;
    QPoint vectorOfTheMovingEvent = mouseStopedPoint - mouseClickedPoint ;

    if( SelectedIndex !=-1){
        AllShape[SelectedIndex]->move(vectorOfTheMovingEvent);
    }

}

void Scene::colorShape(QMouseEvent *event,QColor color)
{
    int selectedIndex = selectObj(event) ;
    if(selectedIndex !=-1 ){

        AllShape[selectedIndex]->setColor(color);

     }


}

int Scene::selectObj(QPoint p){

    for( int i = AllShape.size() - 1 ; i != -1 ; --i) {
       if(AllShape[i]->checkTheSelectedShape(p)){
           return i;
       }
    }//end for loop

    return -1;

}

int Scene::getSelectedIndex() const
{
    return SelectedIndex;
}

void Scene::setSelectedIndex(int newSelectedIndex)
{
    SelectedIndex = newSelectedIndex;
}

int Scene::selectObj(QMouseEvent *event){

    for( int i = AllShape.size() - 1 ; i != -1 ; --i) {
       if(AllShape[i]->checkTheSelectedShape(event->pos())){
           return i;
       }
    }
    return -1;
    //    lastColorOfSelectedShap = scene->AllShape[i]->getColor();
    //    //Set oppicity to the Shape
    //    QColor newColorForSelectedShape = Qt::gray;
    //    newColorForSelectedShape.setAlpha(100);
    //    scene->AllShape[i]->setColor(newColorForSelectedShape);
}
