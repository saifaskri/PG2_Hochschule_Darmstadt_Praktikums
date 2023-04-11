#ifndef STALL_H
#define STALL_H


#include "pony.h"
#define SIZE  20

class Stall
{
public:
    Stall();
    int belegteBoxen();
    bool einstellen(Pony*);
    Pony* herausholen(string s);
    float durchschnittsalter();
    void weidegang();
    void zeigeInfo();
private:
   Pony* pferdeboxen[SIZE];

};

#endif // STALL_H

