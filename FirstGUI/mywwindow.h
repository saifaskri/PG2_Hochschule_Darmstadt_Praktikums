#ifndef MYWWINDOW_H
#define MYWWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MywWindow; }
QT_END_NAMESPACE




class MywWindow : public QMainWindow{

    Q_OBJECT

public:
    MywWindow(QWidget *parent = nullptr);
    ~MywWindow();

private slots:


    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MywWindow *ui;




};


#endif // MYWWINDOW_H
