#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "graphobj.h"

class Rectangle : public GraphObj{

public:
    Rectangle();
    virtual ~Rectangle();
    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint p);


    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

private:
    int width = 0;
    int height = 0;
};

#endif // RECTANGLE_H
