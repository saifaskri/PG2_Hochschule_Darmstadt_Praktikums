#ifndef ISLANDPFERD_H
#define ISLANDPFERD_H

#include "pony.h"

class Islandpferd : public Pony
{
public:
    Islandpferd();
    Islandpferd(string NAME,int Geb,  bool Ekz);
    bool hatEkzem();
    bool isReitbar(int x);
    void zeigeInfo();
private:
    bool ekzemer;
};

#endif // ISLANDPFERD_H
