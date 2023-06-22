#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "graphobj.h"

class Rectangle : public GraphObj{

public:
    Rectangle();

    Rectangle(const Rectangle& graph) ;
    Rectangle &operator=(const Rectangle& graph)  ;

    virtual ~Rectangle();
    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint p);
    void drawBBox(QPainter &painter);
    void calcBBox(QPoint &min, QPoint &max) const ;


    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

private:
    int width = 0;
    int height = 0;
};

#endif // RECTANGLE_H
