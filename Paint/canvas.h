#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include <iostream>



#include "graphobj.h"


class Canvas : public QFrame
{
	Q_OBJECT

public:

	enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
	};

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

    int getSelectedIndex() const;
    void setSelectedIndex(int newSelectedIndex);

    std::vector<GraphObj *> AllShape;

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

    int SelectedIndex = -1 ;
    GraphObj *shape ;

};

#endif // CANVAS_H