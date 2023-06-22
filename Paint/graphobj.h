#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H

#include <QPainter>
#include<QPoint>
#include <QPainter>

#define FONTSIZE 3
#define BboxSize 3


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
    virtual bool drawingIsDone();
    virtual void drawBBox(QPainter &painter)= 0;
    virtual void calcBBox(QPoint &min, QPoint &max) const = 0;

    void setBrushForTheObject(QPainter &painter);

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



    int getFontSize() const;
    void setFontSize(int newFontSize);

private:

    QPoint startPoint;
    QPoint stopPoint;
    QColor color;
    bool outline;
    bool doneDrawing = true;
    Qt::PenStyle penStyle;
    int fontSize = 5;

};

#endif // GRAPHOBJ_H












