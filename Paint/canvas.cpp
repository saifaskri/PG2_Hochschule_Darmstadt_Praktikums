#include "canvas.h"
#include "freehand.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

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
    // Set the background color

    painter.fillRect(rect(), this->canvaBackgroundColor);

    // draw all old Shapes
    scene->draw(painter);
    //if Bbox true Draw it
    if(this->BBox){ scene->drawBBox(painter);}
    //draw the new Shape
    if(shape != nullptr){shape->draw(painter);
        if(this->BBox){ scene->drawBBox(painter);}
    }
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

       if(linetype == LineType::CustomDashLine){
           shape->setPenStyle(Qt::PenStyle::CustomDashLine);
       }else if(linetype == LineType::DotLine){
           shape->setPenStyle(Qt::PenStyle::DotLine);
       }else if(linetype == LineType::DashDotDotLine){
           shape->setPenStyle(Qt::PenStyle::DashDotDotLine);
       }else if(linetype == LineType::DashLine){
           shape->setPenStyle(Qt::PenStyle::DashLine);
       }else if(linetype == LineType::MPenStyle){
           shape->setPenStyle(Qt::PenStyle::MPenStyle);
       }else if(linetype == LineType::SolidLine){
           shape->setPenStyle(Qt::PenStyle::SolidLine);
       }

       bbox = new BBoxDecorator(shape);
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

        // set The Points for the class Canvas (falls wir sie brauchen)
        this->startPoint = event->pos();
        this->StopPoint = event->pos();

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
              scene->AddShape(bbox);
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

bool Canvas::getBBox() const
{
    return BBox;
}

void Canvas::setBBox(bool newBBox)
{
    BBox = newBBox;
}


void Canvas::setLinetype(int newLinetype)
{
    linetype = (Canvas::LineType) newLinetype;
}

QColor Canvas::getCanvaBackgroundColor() const
{
    return canvaBackgroundColor;
}

void Canvas::setCanvaBackgroundColor(const QColor &newCanvaBackgroundColor)
{
    canvaBackgroundColor = newCanvaBackgroundColor;
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
