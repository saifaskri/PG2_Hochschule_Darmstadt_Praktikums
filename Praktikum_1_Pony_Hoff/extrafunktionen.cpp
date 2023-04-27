#include "extrafunktionen.h"

ExtraFunktionen::ExtraFunktionen()
{

}

void ExtraFunktionen::Ausgabe(string x)
{
    cout << left << setw(WIDTH) << setfill(SEPARATOR) <<x;

}
