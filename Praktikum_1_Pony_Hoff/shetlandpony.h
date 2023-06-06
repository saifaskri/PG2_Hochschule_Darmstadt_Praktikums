#ifndef SHETLANDPONY_H
#define SHETLANDPONY_H


#include "pony.h"

class Shetlandpony : public Pony
{
public:
    Shetlandpony();
    Shetlandpony(string NAME,int Geb,  bool K_lieb);
    bool istKinderlieb();
    bool isReitbar(int x);
    void zeigeInfo();

private:
    bool kinderlieb;

};

#endif // SHETLANDPONY_H
