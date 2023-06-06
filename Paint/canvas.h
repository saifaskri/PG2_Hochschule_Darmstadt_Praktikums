#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include <iostream>



#include "graphobj.h"
#include "scene.h"

class Canvas : public QFrame
{
	Q_OBJECT

public:

	enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
	};

    enum InteractionMode{ CREAT, DEL, COL, TRAFO };


	Canvas(QWidget *parent = 0);
	~Canvas();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

	void clearCanvas(void);
	void setPrimitiveMode(int mode);

    QPoint getStartPos() const;
    void setStartPos(QPoint newStartPos);

    QPoint getStopPos() const;
    void setStopPos(QPoint newStopPos);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    bool getOutline() const;
    void setOutline(bool newOutline);



    //InteractionMode getOparation() const;
    void setOparation(InteractionMode newOparation);

    void Create(QMouseEvent *event);
    void Delete(QMouseEvent *event);
    void Coloring(QMouseEvent *event);
    void Move(QPoint startPoint, QPoint endPoint);



protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:

	bool dragging;
	PrimitiveMode type;
    QColor color;
    bool outline = true;

    Scene* scene;
    GraphObj *shape ;


    QColor lastColorOfSelectedShap;

    InteractionMode oparation ;

    QPoint startPoint;
    QPoint StopPoint;


};

#endif // CANVAS_H
