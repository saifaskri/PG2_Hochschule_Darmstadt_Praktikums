#ifndef FREEHAND_H
#define FREEHAND_H


#include "graphobj.h"
#include <QPixmap>
#include <vector>

#define RANGE 10

struct koordinate{
    QPoint startPoint;
    QPoint stopPoint ;
    koordinate(){};
    koordinate(QPoint start, QPoint stop):startPoint(start),stopPoint(stop){};
};

class FreeHand : public GraphObj{
public:
    FreeHand();
    virtual ~FreeHand();
    void draw(QPainter &painter);
    bool checkTheSelectedShape(QPoint);
    std::vector<koordinate *>pointHestory;
};

#endif // FREEHAND_H
