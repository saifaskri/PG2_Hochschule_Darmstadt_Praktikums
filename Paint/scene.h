#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include <QMouseEvent>
#include <QColor>

#include"graphobj.h"


class Scene
{
public:

    Scene();
    ~Scene();
    void draw(QPainter &painter);

    void deleteShape(QMouseEvent *event);
    void AddShape(GraphObj* obj);
    void DeleteAllShape();

    void moveShape(QPoint startPoint, QPoint endPoint );
    void colorShape(QMouseEvent *event,QColor color);

    int selectObj(QMouseEvent *event);
    // function overload
    int selectObj(QPoint p);
    int getSelectedIndex() const;
    void setSelectedIndex(int newSelectedIndex);

private:
    std::vector<GraphObj *> AllShape;
    int SelectedIndex = -1 ;
};

#endif // SCENE_H
