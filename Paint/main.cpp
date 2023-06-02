#include <QtWidgets/QApplication>
#include "paint.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setHighDpiScaleFactorRoundingPolicy(
         Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication app(argc, argv);
    Paint w;
    w.show();
    return app.exec();
}

//#include<iostream>
//void groupBoxChanged(){
//    std::cout<<"clicked"<<std::endl;
//}

//#include <QtWidgets>

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    QWidget window;
//    QVBoxLayout layout(&window);

//    QGroupBox groupBox("Radio Buttons");
//    QVBoxLayout groupLayout;
//    groupBox.setLayout(&groupLayout);

//    QRadioButton radio1("Option 1");
//    QRadioButton radio2("Option 2");
//    QRadioButton radio3("Option 3");

//    QButtonGroup buttonGroup;
//    buttonGroup.addButton(&radio1);
//    buttonGroup.addButton(&radio2);
//    buttonGroup.addButton(&radio3);

//    groupLayout.addWidget(&radio1);
//    groupLayout.addWidget(&radio2);
//    groupLayout.addWidget(&radio3);

//    layout.addWidget(&groupBox);


//    window.setLayout(&layout);
//    window.show();

//    return app.exec();
//}
