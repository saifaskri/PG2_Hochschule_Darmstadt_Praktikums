#include "mywwindow.h"
#include "./ui_mywwindow.h"

MywWindow::MywWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MywWindow)
{
    ui->setupUi(this);
}

void MywWindow::on_horizontalSlider_valueChanged(int value){
    ui->myBar->setValue(value);
}


MywWindow::~MywWindow()
{
    delete ui;
}

