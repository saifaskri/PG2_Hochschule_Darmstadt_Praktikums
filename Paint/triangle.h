#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "graphobj.h"



struct StratStopPoints{
    QPoint startPoint;
    QPoint stopPoint ;
    StratStopPoints(){};
    StratStopPoints(QPoint start, QPoint stop):startPoint(start),stopPoint(stop){};
};

class Triangle : public GraphObj{

public:

    Triangle();
    Triangle(const Triangle& graph) ;
    Triangle &operator=(const Triangle& graph)  ;
    ~Triangle();


    void draw(QPainter &painter);
    bool checkTheSelectedShape(QPoint p);
    void move(QPoint vector);
    bool drawingIsDone();

    bool getDone() const;
    void setDone(bool newDone);


    int getNumberOfDrawedLine() const;
    void setNumberOfDrawedLine(int newNumberOfDrawedLine);

    bool getReleasedClicked() const;
    void setReleasedClicked(bool newReleasedClicked);

    std::vector<StratStopPoints*> lineList;

private:
    bool done = true;
    int numberOfDrawedLine = 0;
    bool releasedClicked = false;
};

#endif // TRIANGLE_H
