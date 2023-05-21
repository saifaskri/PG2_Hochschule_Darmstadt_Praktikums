#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bg = new QButtonGroup(this);

    bg->addButton(ui->plus_op,0);
    bg->addButton(ui->minus_op,1);
    bg->addButton(ui->mal_op,2);
    bg->addButton(ui->geteilt_op,3);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::myCalc()
{
    float op1 = ui->input_OP1->text().toFloat() ;
    float op2 = ui->input_OP2->text().toFloat() ;

    float res = 0.0 ;

    switch (bg->checkedId()) {
    case 20:
        res = op1+ op2;
        break;
    case 1:
        res = op1 - op2;
        break;
    case 2:
        res = op1 * op2;
        break;
    case 3:
        res = op1 / op2;
        break;
    default:
        break;
    }


    ui->summe_label->setText(QString::number(res));

}

