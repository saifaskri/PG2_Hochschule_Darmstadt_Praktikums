#ifndef FREEHAND_H
#define FREEHAND_H


#include "graphobj.h"
#include <QPixmap>
#include <vector>

#define RANGEs 10

struct koordinate{
    QPoint startPoint;
    QPoint stopPoint ;
    koordinate(){};
    koordinate(QPoint start, QPoint stop):startPoint(start),stopPoint(stop){};
};

class FreeHand : public GraphObj{
public:
    FreeHand();

    FreeHand(const FreeHand& graph) ;
    FreeHand &operator=(const FreeHand& graph)  ;
    virtual ~FreeHand();

    void draw(QPainter &painter);
    void move(QPoint vector);
    bool checkTheSelectedShape(QPoint);
    std::vector<koordinate *>pointHestory;
};

#endif // FREEHAND_H
