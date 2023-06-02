#include "canvas.h"

#include "freehand.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

bool CheckIfShapeIsAcceptable(GraphObj *obj){

    // Free hand is allways true
    FreeHand* freeHandObj;
    if( (freeHandObj = dynamic_cast<FreeHand*>(obj)) ){
        return true;
    }


    int length = std::sqrt( (obj->getStartPoint().x() - obj->getStopPoint().x()) *
                            (obj->getStartPoint().x() - obj->getStopPoint().x()) +
                            (obj->getStartPoint().y() - obj->getStopPoint().y()) *
                            (obj->getStartPoint().y() - obj->getStopPoint().y()) );
    if(length > 20)
        return true;
    else
        return false;
}

Canvas::Canvas(QWidget *parent): QFrame(parent){
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);
    type = NONE;
    dragging = false;
    shape = nullptr;

}

Canvas::~Canvas(){

}

QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}

void Canvas::clearCanvas(void){

    AllShape.clear();

}

void Canvas::setPrimitiveMode(int mode){

    type = (Canvas::PrimitiveMode)mode;

}

void Canvas::paintEvent(QPaintEvent *event){

    QFrame::paintEvent(event);  // parent class draws border
    QPainter painter(this);

    for(int i = 0; i < (int)AllShape.size(); i++){
        AllShape[i]->draw(painter);
    }

    //draw the Shape
    if(shape != nullptr){shape->draw(painter);}

}


void Canvas::Create(QMouseEvent *event){

    switch (type) {
    case LINE:
        shape = new Line();
    break;
    case CIRCLE:
        shape = new Circle();
    break;
    case RECTANGLE:
        shape = new Rectangle ();
    break;
    case FREE_HAND:
        shape = new FreeHand ();
    break;
    case TRIANGLE:
        shape = new Triangle();
    break;
    case NONE:
        shape = nullptr;
    break;
    default:
        break;
    }

    if(shape != nullptr){
       shape->setStartPoint(event->pos());
       shape->setStopPoint(event->pos());
       shape->setColor(color);
       shape->setOutline(outline);
    }
}


void Canvas::Delete(QMouseEvent *event){

    selectObj(event);
    if(getSelectedIndex() == -1) return;

    AllShape.erase(AllShape.begin()+getSelectedIndex());
    //reset SelectedIndex to -1 for the next Shape
    setSelectedIndex(-1) ;
    update();


}

void Canvas::Coloring(QMouseEvent *event){

    selectObj(event);
    if(getSelectedIndex() == -1) return;

    AllShape[getSelectedIndex()]->setColor(getColor());

    setSelectedIndex(-1) ;

    update();

}

void Canvas::Move(QMouseEvent *event ){

    selectObj(event);
    if(getSelectedIndex() == -1) return;
    QPoint newPlace;

    newPlace.setX(AllShape[getSelectedIndex()]->getStartPoint().x() + (event->pos().x() - this->startPoint.x() ));

    newPlace.setY(AllShape[getSelectedIndex()]->getStartPoint().y() + (event->pos().y() - this->startPoint.y() ));

    AllShape[getSelectedIndex()]->setStartPoint(newPlace);
    std::cout<<"implementiere mich Move"<<std::endl;
    update();

}

void Canvas::selectObj(QMouseEvent *event){

//    lastColorOfSelectedShap = AllShape[i]->getColor();
//    //Set oppicity to the Shape
//    QColor newColorForSelectedShape = Qt::gray;
//    newColorForSelectedShape.setAlpha(100);
//    AllShape[i]->setColor(newColorForSelectedShape);

    // select Object to be deleted
    SelectedIndex = -1 ;

    for( int i = AllShape.size() - 1 ; i != -1 ; --i) {

       if(AllShape[i]->checkTheSelectedShape(event->pos())){

           SelectedIndex = i ;

           break;

        }
    }//end for loop


}




void Canvas::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        dragging = true;

        //begin block
            //if Object was selected but not deleted
            if(SelectedIndex != -1){
             // AllShape[SelectedIndex]->setColor(lastColorOfSelectedShap);
              SelectedIndex = -1;
            }
        //end Block

        this->startPoint = event->pos();

        switch (oparation) {
            case CREAT:
                Create(event);
                break;
            case DEL:
                Delete(event);
                break;
            case COL:
                Coloring(event);
                break;
            case TRAFO:
                Move(event);
                break;
            default:
                break;
        }



        update();
    }

}

void Canvas::mouseMoveEvent(QMouseEvent *event){

    if ((event->buttons() & Qt::LeftButton) && dragging) {

        if(oparation == CREAT){
            if(shape == nullptr){return;}
            shape->setStopPoint(event->pos());
            if(type == FREE_HAND && oparation == CREAT){
                koordinate *k = new koordinate(shape->getStartPoint(),event->pos());
                FreeHand* freeHandObj = dynamic_cast<FreeHand*>(shape);
                freeHandObj->pointHestory.push_back(k);
                shape->setStartPoint(event->pos());
            }
        }else if(oparation == TRAFO){
            Move(event);
        }

        update();

    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton && dragging) {

        dragging = false;

        if(shape != nullptr && type != NONE){
           shape->setStopPoint(event->pos());
           //Save Shape but need more Contorlle for how much big is my shape
           if(CheckIfShapeIsAcceptable(shape)){
               AllShape.push_back(shape);
               shape = nullptr;
           }
        }

        update();

    }
}

//Canvas::InteractionMode Canvas::getOparation() const
//{
//    return oparation;
//}

void Canvas::setOparation(InteractionMode newOparation)
{
    oparation = newOparation;
}


int Canvas::getSelectedIndex() const
{
    return SelectedIndex;
}

void Canvas::setSelectedIndex(int newSelectedIndex)
{
    SelectedIndex = newSelectedIndex;
}

void Canvas::resizeEvent(QResizeEvent *event){
    QFrame::resizeEvent(event);
}

bool Canvas::getOutline() const
{
    return outline;
}

void Canvas::setOutline(bool newOutline)
{
    outline = newOutline;
}

QColor Canvas::getColor() const
{
    return color;
}

void Canvas::setColor(const QColor &newColor)
{
    color = newColor;
}
