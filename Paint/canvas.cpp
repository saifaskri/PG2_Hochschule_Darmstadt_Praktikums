#include "canvas.h"
#include "freehand.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

bool CheckIfShapeIsAcceptable(GraphObj *obj){
    // Free hand is allways true
    FreeHand* freeHandObj;
    if( (freeHandObj = dynamic_cast<FreeHand*>(obj)) ){return true;}

    int length = std::sqrt( (obj->getStartPoint().x() - obj->getStopPoint().x()) *
                            (obj->getStartPoint().x() - obj->getStopPoint().x()) +
                            (obj->getStartPoint().y() - obj->getStopPoint().y()) *
                            (obj->getStartPoint().y() - obj->getStopPoint().y()) );
    if(length > 20) return true;
    else return false;
}

Canvas::Canvas(QWidget *parent): QFrame(parent){
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);
    scene = new Scene();
    type = NONE;
    dragging = false;
    shape = nullptr;
}

Canvas::~Canvas(){
    delete shape;
    delete scene;
}

QSize Canvas::minimumSizeHint() const{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const{
    return QSize(640, 480);
}

void Canvas::clearCanvas(void){
    scene->DeleteAllShape();
}

void Canvas::setPrimitiveMode(int mode){
    type = (Canvas::PrimitiveMode)mode;
}

void Canvas::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);  // parent class draws border
    QPainter painter(this);
    // draw all old Shapes
    scene->draw(painter);
    //draw the new Shape
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
    scene->deleteShape(event);
    update();
}

void Canvas::Coloring(QMouseEvent *event){
    scene->colorShape(event,getColor());
    update();
}

void Canvas::Move(QPoint startPoint, QPoint endPoint ){
    scene->moveShape(startPoint,endPoint);
    update();
}

void Canvas::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        dragging = true;

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

                this->startPoint = event->pos();
                this->StopPoint = event->pos();
                //set The Object that was selected
                scene->setSelectedIndex(scene->selectObj(event->pos()));
                Move( this->startPoint, this->StopPoint);
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
            this->StopPoint = event->pos();
            Move(this->startPoint,this->StopPoint);
            this->startPoint = event->pos();

        }

        update();

    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && dragging) {
        dragging = false;
        //Create
        if(shape != nullptr && type != NONE){
           shape->setStopPoint(event->pos());
           //Save Shape but need more Contorlle for how much big is my shape
           if(CheckIfShapeIsAcceptable(shape)){
               scene->AddShape(shape);
               shape = nullptr;
           }
        }
        if(oparation == TRAFO){
            this->StopPoint = event->pos();
            Move(this->startPoint,this->StopPoint);
            //reinitial The Object that was selected to -1
            scene->setSelectedIndex(-1);
        }
        update();
    }
}

void Canvas::setOparation(InteractionMode newOparation){
    oparation = newOparation;
}

void Canvas::resizeEvent(QResizeEvent *event){
    QFrame::resizeEvent(event);
}

bool Canvas::getOutline() const{
    return outline;
}

void Canvas::setOutline(bool newOutline){
    outline = newOutline;
}

QColor Canvas::getColor() const{
    return color;
}

void Canvas::setColor(const QColor &newColor){
    color = newColor;
}
