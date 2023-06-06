#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H

#include<QPainter>
#include <QPoint>
#include<iostream>


class GraphObject
{
public:
    GraphObject();
    virtual void draw(QPainter &p);
    virtual bool selected(QPoint p);



    QPoint getStartPoint() const;
    void setStartPoint(QPoint newStartPoint);

    QPoint getStopPoint() const;
    void setStopPoint(QPoint newStopPoint);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    bool getOutline() const;
    void setOutline(bool newOutline);

private:
   QPoint startPoint;
   QPoint stopPoint;
   QColor color;
   bool outline;

};

#endif // GRAPHOBJECT_H
