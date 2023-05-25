#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include "canvas.h"
#include "circle.h"
#include "line.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent)
{
	setFrameStyle(QFrame::Box);
	setMouseTracking(true);

    type = NONE;
	dragging = false;
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}

void Canvas::clearCanvas(void)
{
    AllShape.clear();
	// TODO
}

void Canvas::setPrimitiveMode(int mode)
{
	type = (Canvas::PrimitiveMode)mode;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    for(GraphObject *myobj : AllShape){
        myobj->draw(painter);
    }




    if(obj != nullptr){
        obj->draw(painter);
    }

    // white background (inside parent's border)
    //painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);

    // TODO; implement drawing functionality for all the primitives!
    // The following is just a basic example and to be removed...
    /*
    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
    painter.drawLine(QPoint(2, height()/2), QPoint(width()-2, height()/2));
    painter.drawLine(QPoint(width()/2, 2), QPoint(width()/2, height()-2));
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(QPoint(width()/2, height()/2), 8, 8);
    */
}

void Canvas::resizeEvent(QResizeEvent *event) 
{
	QFrame::resizeEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		dragging = true;

        if(SelectedIndex != -1){
            AllShape[SelectedIndex]->setColor(lastColorOfSelectedShap);
        }

        SelectedIndex = -1;

        switch (type) {
        case NONE:
            obj = nullptr;
            break;
        case CIRCLE:
            obj = new Circle();
            break;
        case LINE:
            obj = new Line();
            break;
        default:
            obj = nullptr;
            break;
        }

        if(type != NONE){
            obj->setStartPoint(event->pos());
            obj->setStopPoint(event->pos());
            obj->setColor(this->getColor());
            obj->setOutline(this->outline);
        }else{

             for( int i = AllShape.size() - 1 ; i != -1 ; --i) {
                if(AllShape[i]->selected(event->pos())){
                    SelectedIndex = i;
                    lastColorOfSelectedShap = AllShape[i]->getColor();

                    AllShape[i]->setColor(Qt::red);
                    break;
                }
            }

        }

		// TODO; implement mouse interaction
		// Mouse position given as follows
		//QPoint currPos = event->pos();

		update();
	}
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && dragging) {

        if(obj!=nullptr){
            obj->setStopPoint(event->pos());
        }

		update();
	}
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && dragging) {
		dragging = false;

        if(obj!=nullptr){
            obj->setStopPoint(event->pos());
            //prüf ob Obj klein ist
            AllShape.push_back(obj);
            obj = nullptr;
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
