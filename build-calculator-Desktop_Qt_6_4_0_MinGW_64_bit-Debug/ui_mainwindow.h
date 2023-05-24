/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *input_OP1;
    QLabel *label_OP1;
    QLabel *label_OP2;
    QPushButton *summe_btn;
    QGroupBox *groupBox_operationen;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *plus_op;
    QRadioButton *minus_op;
    QRadioButton *mal_op;
    QRadioButton *geteilt_op;
    QLineEdit *summe_label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *input_OP2;
    QGroupBox *groupBox;
    QRadioButton *myminus;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1002, 595);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        input_OP1 = new QLineEdit(centralwidget);
        input_OP1->setObjectName("input_OP1");
        input_OP1->setGeometry(QRect(80, 140, 261, 28));
        label_OP1 = new QLabel(centralwidget);
        label_OP1->setObjectName("label_OP1");
        label_OP1->setGeometry(QRect(80, 90, 63, 20));
        label_OP2 = new QLabel(centralwidget);
        label_OP2->setObjectName("label_OP2");
        label_OP2->setGeometry(QRect(570, 90, 125, 20));
        summe_btn = new QPushButton(centralwidget);
        summe_btn->setObjectName("summe_btn");
        summe_btn->setGeometry(QRect(870, 140, 83, 29));
        groupBox_operationen = new QGroupBox(centralwidget);
        groupBox_operationen->setObjectName("groupBox_operationen");
        groupBox_operationen->setGeometry(QRect(400, 50, 80, 272));
        verticalLayout_2 = new QVBoxLayout(groupBox_operationen);
        verticalLayout_2->setObjectName("verticalLayout_2");
        plus_op = new QRadioButton(groupBox_operationen);
        plus_op->setObjectName("plus_op");
        QFont font;
        font.setPointSize(20);
        plus_op->setFont(font);
        plus_op->setChecked(true);

        verticalLayout_2->addWidget(plus_op);

        minus_op = new QRadioButton(groupBox_operationen);
        minus_op->setObjectName("minus_op");
        minus_op->setFont(font);

        verticalLayout_2->addWidget(minus_op);

        mal_op = new QRadioButton(groupBox_operationen);
        mal_op->setObjectName("mal_op");
        mal_op->setFont(font);

        verticalLayout_2->addWidget(mal_op);

        geteilt_op = new QRadioButton(groupBox_operationen);
        geteilt_op->setObjectName("geteilt_op");
        geteilt_op->setFont(font);

        verticalLayout_2->addWidget(geteilt_op);

        summe_label = new QLineEdit(centralwidget);
        summe_label->setObjectName("summe_label");
        summe_label->setGeometry(QRect(40, 390, 631, 28));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 110, 259, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(570, 113, 281, 61));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        input_OP2 = new QLineEdit(layoutWidget1);
        input_OP2->setObjectName("input_OP2");

        verticalLayout->addWidget(input_OP2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(750, 260, 161, 211));
        myminus = new QRadioButton(groupBox);
        myminus->setObjectName("myminus");
        myminus->setGeometry(QRect(30, 40, 112, 26));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(20, 90, 112, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1002, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);
        QObject::connect(summe_btn, SIGNAL(clicked()), MainWindow, SLOT(myCalc()));
        QObject::connect(summe_btn, SIGNAL(clicked()), MainWindow, SLOT(timclick()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        input_OP1->setText(QString());
        label_OP1->setText(QCoreApplication::translate("MainWindow", "OP1", nullptr));
        label_OP2->setText(QCoreApplication::translate("MainWindow", "OP2", nullptr));
        summe_btn->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        groupBox_operationen->setTitle(QCoreApplication::translate("MainWindow", "Operation", nullptr));
        plus_op->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minus_op->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        mal_op->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        geteilt_op->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Groh54wz5trhupBox", nullptr));
        myminus->setText(QCoreApplication::translate("MainWindow", "m,nius", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
