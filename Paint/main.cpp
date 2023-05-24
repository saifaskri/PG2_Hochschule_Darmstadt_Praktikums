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

//#include <iostream>
//#include <cmath>

//struct Point {
//    double x;
//    double y;
//};

//double calculateAngle(Point a, Point b) {
//    double angle = atan2(b.y - a.y, b.x - a.x);
//    // Winkel in Bogenmaß
//    if (angle < 0) {
//        angle += 2 * M_PI;
//    }
//    // Winkel in Grad umrechnen
//    angle = angle * 180.0 / M_PI;
//    return angle;
//}

//int main() {
//    Point a = {0.0, 0.0};
//    Point b = {1.0, 1.0};
//    double angle = calculateAngle(a, b);
//    std::cout << "Winkel zwischen a und b: " << angle << " Grad" << std::endl;
//    return 0;
//}



