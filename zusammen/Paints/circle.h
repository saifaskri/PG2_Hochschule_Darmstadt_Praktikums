#ifndef CIRCLE_H
#define CIRCLE_H


#include "graphobject.h"

class Circle : public GraphObject
{
public:
    Circle();
    void draw(QPainter &p);
    bool selected(QPoint p);

    int getRadius() const;
    void setRadius(int newRadius);

private:
    int radius;
};

#endif // CIRCLE_H
