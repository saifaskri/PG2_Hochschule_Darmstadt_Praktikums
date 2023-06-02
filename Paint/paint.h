#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include <QGroupBox>
#include<QRadioButton>
#include<QVBoxLayout>
#include <QButtonGroup>



class QPushButton;
class QComboBox;
class QLabel;
class QCheckBox;
class Canvas;
class QGroupBox;
class QRadioButton;
class QVBoxLayout;
class QButtonGroup;


class Paint : public QWidget
{
	Q_OBJECT

public:

	Paint(QWidget *parent = 0);
	~Paint();

private slots:
	void clearBtnPressed();
    void deleteBtnPressed();
    void colorBtnPressed();
	void primModeChanged();
    void showOutlineOnly(bool);
    void BBoxPressed(bool bbox);
    void groupBoxChanged();


private:
    Canvas *viewport;
    QPushButton *btnClearCanvas;
    QComboBox *cobPrimModes;
    QLabel *lblPrimModes;
    QPushButton *btnDeleteObj;
    QPushButton *btnChangeCol;
    QCheckBox *cbOutline;
    QCheckBox *BBox;


    QGroupBox* groupBox ;
    QVBoxLayout* groupBoxLayout;
    QRadioButton* creating ;
    QRadioButton* deleting ;
    QRadioButton* coloring ;
    QRadioButton* moving ;

    QButtonGroup *action;

};

#endif // PAINT_H



























