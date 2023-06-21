#ifndef ORDERS_H
#define ORDERS_H
#include <QWidget>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class Orders; }
QT_END_NAMESPACE

class Dish;

class Orders : public QWidget
{
    Q_OBJECT

public:
    Orders(QWidget *parent = nullptr);
    ~Orders();

protected slots:
    void calcPrice();
    void printOrder();
    void clearOrder();

protected:
    void createOrder();

private:
    Ui::Orders *ui;

    Dish *dish;
};
#endif // ORDERS_H
