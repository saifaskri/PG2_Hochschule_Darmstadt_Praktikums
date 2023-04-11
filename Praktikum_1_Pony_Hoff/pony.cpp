#include "pony.h"

Pony::Pony()
{

}

string Pony::gibName()
{
    return name;
}

int Pony::gibgebutsJahr()
{
    return gebutsJahr;
}

void Pony::setzePos(const Position &p)
{
    ort.x =  p.x;
    ort.y = p.y;
}

bool Pony::istReitbar(int x)
{
    return true;
}

void Pony::zeigeInfo()
{

}
