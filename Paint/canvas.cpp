#include "canvas.h"

#include "freehand.h"
#include "line.h"
#include "circle.h"
#include "qforeach.h"
#include "rectangle.h"

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

Canvas::Canvas(QWidget *parent): QFrame(parent)
{
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);
    type = NONE;
    dragging = false;

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

void Canvas::paintEvent(QPaintEvent *event)
{

    QFrame::paintEvent(event);  // parent class draws border
    QPainter painter(this);

    for(GraphObj *obj : AllShape) {
        obj->draw(painter);
    }

    if(shape != nullptr){
        shape->draw(painter);
    }

}

void Canvas::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton) {
        dragging = true;
        if(type != NONE){
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
            }

        }else{

            // select Object to be deleted
            //std::cout<<" ( "<<event->pos().x()<<" , "<<event->pos().y()<<" ) "<<std::endl;
            for( int i = AllShape.size() - 1 ; i != -1 ; --i) {
               if(AllShape[i]->checkTheSelectedShape(event->pos())){
                   SelectedIndex = i ;
                   break;
               }
            }

        }

        update();
    }


}

void Canvas::mouseMoveEvent(QMouseEvent *event){

    if ((event->buttons() & Qt::LeftButton) && dragging) {

        if(type != NONE){

            if(shape != nullptr){
                shape->setStopPoint(event->pos());
            }

            if(type == FREE_HAND){

                koordinate *k = new koordinate(shape->getStartPoint(),event->pos());
                FreeHand* freeHandObj = dynamic_cast<FreeHand*>(shape);
                freeHandObj->pointHestory.push_back(k);
                shape->setStartPoint(event->pos());

            }

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
