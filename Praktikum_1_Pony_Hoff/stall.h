#ifndef STALL_H
#define STALL_H

#include <ctime>
#include <vector>
#include <stdlib.h>

#include "pony.h"

#define SIZE  20

struct Weide
{
    float Xw;
    float Yw;
    float Lange;
    float Breite;
    Position Ursprng ;
    Weide(float Xw =(float)rand()/RAND_MAX ,float Yw = (float)rand()/RAND_MAX,float Lange = 40, float Breite =30 ): Xw(Xw), Yw(Yw), Lange(Lange),  Breite(Breite),Ursprng(Xw+Lange,Yw+Breite){}

};

class Stall
{
public:
    Stall();
    int belegteBoxen();
    bool einstellen(Pony*);
    Pony* herausholen(string name);
    float durchschnittsalter();
    void weidegang(Weide weide);
    void zeigeInfo();
    int berechneJahr();
    vector<Pony*> getAllPonysFromPferdBoxen();
    int getPferdeboxen_belegung() const;
    void setPferdeboxen_belegung(int newPferdeboxen_belegung);

private:
   Pony* pferdeboxen[SIZE];
   int pferdeboxen_belegung = 0;

};

#endif // STALL_H

