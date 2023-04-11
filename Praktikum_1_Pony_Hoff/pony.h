#ifndef PONY_H
#define PONY_H
#include <iostream>
using namespace std;

struct Position
{
  float x ;
  float y ;
  //Position(float x,float y):x(x),y(y) {}
};

class Pony
{
public:
    Pony();
    string gibName();
    int gibgebutsJahr();
    void setzePos(const Position&);
    bool istReitbar(int x) ;
    void zeigeInfo();

protected:
    int gebutsJahr;
    string name;
    Position ort;
};

#endif // PONY_H
