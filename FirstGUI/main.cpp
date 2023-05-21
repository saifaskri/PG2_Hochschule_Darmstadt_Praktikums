#include "mywwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MywWindow w;
    w.show();
    return a.exec();
}
