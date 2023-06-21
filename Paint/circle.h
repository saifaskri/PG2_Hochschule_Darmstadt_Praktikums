#ifndef CIRCLE_H
#define CIRCLE_H


#include "graphobj.h"

class Circle: public GraphObj{

public:
    Circle();
    Circle(const Circle &graph) ;
    Circle &operator=(const Circle& graph);

     ~Circle();

    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint);

    int getDiameter() const;
    void setDiameter(int newDiameter);

private:
 int diameter;

};

#endif // CIRCLE_H
