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

	enum PrimitiveMode {NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON};

    enum InteractionMode{ CREAT, DEL, COL, TRAFO };

    enum LineType{ CustomDashLine , DotLine, DashDotDotLine, DashLine, MPenStyle, SolidLine };

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

    QColor getCanvaBackgroundColor() const;
    void setCanvaBackgroundColor(const QColor &newCanvaBackgroundColor);

    void setLinetype(int newLinetype);

    bool getBBox() const;
    void setBBox(bool newBBox);

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
    GraphObj *bbox ;


    QColor lastColorOfSelectedShap;

    QColor canvaBackgroundColor = Qt::white;

    InteractionMode oparation ;

    LineType linetype = LineType::SolidLine;

    QPoint startPoint;
    QPoint StopPoint;

    bool BBox = false;


};

#endif // CANVAS_H
