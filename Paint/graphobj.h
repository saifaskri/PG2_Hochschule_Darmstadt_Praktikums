#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H

#include <QPainter>
#include<QPoint>
#include <QPainter>

#define FONTSIZE 3

class GraphObj
{
public:

    GraphObj();

    GraphObj(const GraphObj& graph) = delete ;
    GraphObj& operator=(const GraphObj& graph) = delete  ;
    virtual ~GraphObj();

    virtual void draw(QPainter &painter) = 0;
    virtual void move(QPoint vector) = 0;
    virtual bool checkTheSelectedShape(QPoint) = 0 ;
    void setBrushForTheObject(QPainter &painter);
    virtual bool drawingIsDone();

    QPoint getStopPoint() const;
    void setStopPoint(QPoint newStopPoint);

    QPoint getStartPoint() const;
    void setStartPoint(QPoint newStartPoint);

    bool getOutline() const;
    void setOutline(bool newOutline);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    bool getDoneDrawing() const;
    void setDoneDrawing(bool newDoneDrawing);


    void setPenStyle(Qt::PenStyle newPenStyle);

private:

    QPoint startPoint;
    QPoint stopPoint;
    QColor color;
    bool outline;
    bool doneDrawing = true;

    Qt::PenStyle penStyle;

};

#endif // GRAPHOBJ_H












