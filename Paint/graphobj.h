#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H

#include "qpainter.h"
#include<QPoint>
#include <QPainter>


class GraphObj
{
public:

    GraphObj();
    virtual ~GraphObj();

    virtual void draw(QPainter &painter) = 0;

    QPoint getStopPoint() const;
    void setStopPoint(QPoint newStopPoint);

    QPoint getStartPoint() const;
    void setStartPoint(QPoint newStartPoint);

    virtual bool checkTheSelectedShape(QPoint) = 0 ;

    bool getOutline() const;

    void setOutline(bool newOutline);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    void setBrushForTheObject(QPainter &painter);


private:

    QPoint startPoint;
    QPoint stopPoint;
    QColor color;
    bool outline;



};

#endif // GRAPHOBJ_H
