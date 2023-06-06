#ifndef CANVAS_H
#define CANVAS_H

#include "graphobject.h"

#include <QFrame>

class Canvas : public QFrame
{
	Q_OBJECT

public:
	enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
	};

	Canvas(QWidget *parent = 0);
	~Canvas();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

	void clearCanvas(void);
	void setPrimitiveMode(int mode);

    QColor getColor() const;
    void setColor(const QColor &newColor);

    bool getOutline() const;
    void setOutline(bool newOutline);
    std::vector<GraphObject *> AllShape;

    int getSelectedIndex() const;
    void setSelectedIndex(int newSelectedIndex);


protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	bool dragging;
	PrimitiveMode type;
    GraphObject *obj;
    QColor color;
    bool outline = true;
    int SelectedIndex = -1;
    QColor lastColorOfSelectedShap;

};

#endif // CANVAS_H
