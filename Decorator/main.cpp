#include <QApplication>
#include "orders.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Orders w;
    w.show();
    return a.exec();
}
