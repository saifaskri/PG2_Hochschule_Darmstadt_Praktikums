/********************************************************************************
** Form generated from reading UI file 'orders.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERS_H
#define UI_ORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Orders
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBoxGerichte;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblGericht;
    QComboBox *cobGericht;
    QSpacerItem *verticalSpacer;
    QLabel *lblGetraenk;
    QListWidget *lwGetraenk;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *lblBeilagen;
    QListWidget *lwBeilagen;
    QGroupBox *groupBoxRechnung;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnPreis;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lePreis;
    QLabel *lblWaehrung;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnStorno;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnRechnung;

    void setupUi(QWidget *Orders)
    {
        if (Orders->objectName().isEmpty())
            Orders->setObjectName("Orders");
        Orders->resize(1230, 632);
        verticalLayout_5 = new QVBoxLayout(Orders);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBoxGerichte = new QGroupBox(Orders);
        groupBoxGerichte->setObjectName("groupBoxGerichte");
        QFont font;
        font.setPointSize(10);
        groupBoxGerichte->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBoxGerichte);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblGericht = new QLabel(groupBoxGerichte);
        lblGericht->setObjectName("lblGericht");

        verticalLayout_2->addWidget(lblGericht);

        cobGericht = new QComboBox(groupBoxGerichte);
        cobGericht->setObjectName("cobGericht");

        verticalLayout_2->addWidget(cobGericht);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        lblGetraenk = new QLabel(groupBoxGerichte);
        lblGetraenk->setObjectName("lblGetraenk");

        verticalLayout_2->addWidget(lblGetraenk);

        lwGetraenk = new QListWidget(groupBoxGerichte);
        lwGetraenk->setObjectName("lwGetraenk");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lwGetraenk->sizePolicy().hasHeightForWidth());
        lwGetraenk->setSizePolicy(sizePolicy);
        lwGetraenk->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(lwGetraenk);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lblBeilagen = new QLabel(groupBoxGerichte);
        lblBeilagen->setObjectName("lblBeilagen");

        verticalLayout->addWidget(lblBeilagen);

        lwBeilagen = new QListWidget(groupBoxGerichte);
        lwBeilagen->setObjectName("lwBeilagen");
        sizePolicy.setHeightForWidth(lwBeilagen->sizePolicy().hasHeightForWidth());
        lwBeilagen->setSizePolicy(sizePolicy);
        lwBeilagen->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(lwBeilagen);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_5->addWidget(groupBoxGerichte);

        groupBoxRechnung = new QGroupBox(Orders);
        groupBoxRechnung->setObjectName("groupBoxRechnung");
        groupBoxRechnung->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBoxRechnung);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnPreis = new QPushButton(groupBoxRechnung);
        btnPreis->setObjectName("btnPreis");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnPreis->sizePolicy().hasHeightForWidth());
        btnPreis->setSizePolicy(sizePolicy1);
        btnPreis->setFont(font);

        verticalLayout_3->addWidget(btnPreis);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lePreis = new QLineEdit(groupBoxRechnung);
        lePreis->setObjectName("lePreis");
        QFont font1;
        font1.setPointSize(12);
        lePreis->setFont(font1);
        lePreis->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lePreis->setReadOnly(true);

        horizontalLayout_2->addWidget(lePreis);

        lblWaehrung = new QLabel(groupBoxRechnung);
        lblWaehrung->setObjectName("lblWaehrung");
        QFont font2;
        font2.setPointSize(16);
        lblWaehrung->setFont(font2);

        horizontalLayout_2->addWidget(lblWaehrung);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(149, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        btnStorno = new QPushButton(groupBoxRechnung);
        btnStorno->setObjectName("btnStorno");
        sizePolicy1.setHeightForWidth(btnStorno->sizePolicy().hasHeightForWidth());
        btnStorno->setSizePolicy(sizePolicy1);
        btnStorno->setFont(font);

        verticalLayout_4->addWidget(btnStorno);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        btnRechnung = new QPushButton(groupBoxRechnung);
        btnRechnung->setObjectName("btnRechnung");
        sizePolicy1.setHeightForWidth(btnRechnung->sizePolicy().hasHeightForWidth());
        btnRechnung->setSizePolicy(sizePolicy1);
        btnRechnung->setFont(font);

        verticalLayout_4->addWidget(btnRechnung);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addWidget(groupBoxRechnung);


        retranslateUi(Orders);

        QMetaObject::connectSlotsByName(Orders);
    } // setupUi

    void retranslateUi(QWidget *Orders)
    {
        Orders->setWindowTitle(QCoreApplication::translate("Orders", "Orders", nullptr));
        groupBoxGerichte->setTitle(QCoreApplication::translate("Orders", "Gerichte", nullptr));
        lblGericht->setText(QCoreApplication::translate("Orders", "Grundgericht", nullptr));
        lblGetraenk->setText(QCoreApplication::translate("Orders", "Getr\303\244nke", nullptr));
        lblBeilagen->setText(QCoreApplication::translate("Orders", "Beilagen", nullptr));
        groupBoxRechnung->setTitle(QCoreApplication::translate("Orders", "Rechnung", nullptr));
        btnPreis->setText(QCoreApplication::translate("Orders", "Berechne Gesamtpreis", nullptr));
        lePreis->setText(QCoreApplication::translate("Orders", "0.00", nullptr));
        lblWaehrung->setText(QCoreApplication::translate("Orders", "\342\202\254", nullptr));
        btnStorno->setText(QCoreApplication::translate("Orders", "Stornieren", nullptr));
        btnRechnung->setText(QCoreApplication::translate("Orders", "Drucke Rechnung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Orders: public Ui_Orders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERS_H
