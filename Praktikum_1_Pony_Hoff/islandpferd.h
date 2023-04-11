#ifndef ISLANDPFERD_H
#define ISLANDPFERD_H

#include "pony.h"

class Islandpferd : public Pony
{
public:
    Islandpferd();
    bool hatEkzem();
    bool isReitbar(int x);
    void zeigeInfo();
private:
    bool ekzemer;
};

#endif // ISLANDPFERD_H
