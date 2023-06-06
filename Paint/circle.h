#ifndef CIRCLE_H
#define CIRCLE_H


#include "graphobj.h"

class Circle: public GraphObj{

public:
    Circle();
    virtual ~Circle();
    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint);

    int getDiameter() const;
    void setDiameter(int newDiameter);

private:
int diameter;

};

#endif // CIRCLE_H
