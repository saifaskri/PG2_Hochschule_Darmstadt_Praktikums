#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QButtonGroup;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void myCalc();
    void timclick();


    void on_groupBox_operationen_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup *bg;

    QButtonGroup *timbg;

};



#endif // MAINWINDOW_H
