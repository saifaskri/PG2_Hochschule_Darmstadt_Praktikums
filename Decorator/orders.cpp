#include <stdio.h>
#include <vector>
#include "orders.h"
#include "ui_orders.h"
#include "dish.h"
#include "dishdecorator.h"

Orders::Orders(QWidget *parent)
    : QWidget(parent), ui(new Ui::Orders), dish(nullptr)
{
    ui->setupUi(this);

    QStringList menus, sides, drinks;
    std::map<std::string, float>::const_iterator it;

    for (it  = Menu::getNamePriceBag().begin();
         it != Menu::getNamePriceBag().end(); ++it)
        menus.append(QString::fromStdString(it->first));
    ui->cobGericht->addItems(menus);

    for (it  = Side::getNamePriceBag().begin();
         it != Side::getNamePriceBag().end(); ++it)
        sides.append(QString::fromStdString(it->first));
    ui->lwBeilagen->addItems(sides);

    for (it =  Drink::getNamePriceBag().begin();
         it != Drink::getNamePriceBag().end(); ++it)
        drinks.append(QString::fromStdString(it->first));
    ui->lwGetraenk->addItems(drinks);

    connect(ui->btnPreis, SIGNAL(clicked()), this, SLOT(calcPrice()));
    connect(ui->btnRechnung, SIGNAL(clicked()), this, SLOT(printOrder()));
    connect(ui->btnStorno, SIGNAL(clicked()), this, SLOT(clearOrder()));
}

Orders::~Orders()
{
    delete ui;
}

void Orders::clearOrder()
{
    ui->lePreis->setText("0.00");
    ui->cobGericht->setCurrentIndex(0);

    QList<QListWidgetItem*> listSides = ui->lwBeilagen->selectedItems();
    for (auto l : listSides)
        l->setSelected(false);

    QList<QListWidgetItem*> listDrink = ui->lwGetraenk->selectedItems();
    for (auto l : listDrink)
        l->setSelected(false);
}

void Orders::calcPrice()
{
    createOrder();

    if (dish) {
        char str[20];
        sprintf(str, "%.2f", dish->getPrice());
        ui->lePreis->setText(str);
    }
}

void Orders::printOrder()
{
    calcPrice();

    if (!dish) {
        fprintf(stderr, "\nKein Gericht gewaehlt!\n");
        fflush(stderr);
        return;
    }

    printf("\n");
    dish->printDesc();

    printf("--------------------------------------\n");
    printf("Gesamtpreis: %23.2f %c\n", dish->getPrice(), 128);
    fflush(stdout);
}

void Orders::createOrder()
{
    if (dish) {
        delete dish;
        dish = nullptr;
    }

    QString menu = ui->cobGericht->itemText(ui->cobGericht->currentIndex());
    dish = new Menu(menu.toStdString());

    QList<QListWidgetItem*> listSides = ui->lwBeilagen->selectedItems();
    for (auto l : listSides)
        dish = new Side(dish, l->text().toStdString());

    QList<QListWidgetItem*> listDrink = ui->lwGetraenk->selectedItems();
    for (auto l : listDrink)
        dish = new Drink(dish, l->text().toStdString());
}
