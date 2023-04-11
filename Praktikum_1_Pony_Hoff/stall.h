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

    int getPferdeboxen_belegung() const;
    void setPferdeboxen_belegung(int newPferdeboxen_belegung);

private:
   Pony* pferdeboxen[SIZE];
   int pferdeboxen_belegung = 0;

};

#endif // STALL_H

