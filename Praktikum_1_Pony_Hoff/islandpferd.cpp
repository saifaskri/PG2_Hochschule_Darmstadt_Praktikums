#include "islandpferd.h"
using namespace std;

Islandpferd::Islandpferd()
{

}

Islandpferd::Islandpferd(string NAME,int Geb,  bool Ekz):Pony(NAME,Geb),ekzemer(Ekz)
{

}

bool Islandpferd::hatEkzem()
{
    return ekzemer;
}

bool Islandpferd::isReitbar(int x)
{
    if(x<=10){
        return true;
    }else{
        cout<<"Islandpferd Alt muss unter 10 sein"<<endl;
        return false;
    }
}

void Islandpferd::zeigeInfo()
{
    Pony::zeigeInfo();
    if(this->hatEkzem()) ExtraFunktionen::Ausgabe("          y");
    else ExtraFunktionen::Ausgabe("          n");
}
