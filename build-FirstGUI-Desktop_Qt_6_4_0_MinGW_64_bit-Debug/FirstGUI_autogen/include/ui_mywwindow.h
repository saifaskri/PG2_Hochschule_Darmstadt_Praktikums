/********************************************************************************
** Form generated from reading UI file 'mywwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWWINDOW_H
#define UI_MYWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MywWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QProgressBar *myBar;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MywWindow)
    {
        if (MywWindow->objectName().isEmpty())
            MywWindow->setObjectName("MywWindow");
        MywWindow->resize(1068, 742);
        centralwidget = new QWidget(MywWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(310, 114, 551, 241));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        myBar = new QProgressBar(widget);
        myBar->setObjectName("myBar");
        myBar->setValue(24);

        verticalLayout->addWidget(myBar);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        MywWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MywWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1068, 25));
        MywWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MywWindow);
        statusbar->setObjectName("statusbar");
        MywWindow->setStatusBar(statusbar);

        retranslateUi(MywWindow);

        QMetaObject::connectSlotsByName(MywWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MywWindow)
    {
        MywWindow->setWindowTitle(QCoreApplication::translate("MywWindow", "MywWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MywWindow: public Ui_MywWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWWINDOW_H
