#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "graphobj.h"
#include "line.h"


class Triangle : public GraphObj{

public:
    Triangle();
    virtual ~Triangle();
    void draw(QPainter &painter);
    bool checkTheSelectedShape(QPoint p);
    void move(QPoint vector);

    bool getDone() const;
    void setDone(bool newDone);
    std::vector<Line*> lineList;
private:
    bool done = false;
};

#endif // TRIANGLE_H
