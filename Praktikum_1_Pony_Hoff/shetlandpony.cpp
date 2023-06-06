#include "shetlandpony.h"
using namespace std;

Shetlandpony::Shetlandpony()
{

}

Shetlandpony::Shetlandpony(string NAME,int Geb, bool K_lieb):Pony(NAME,Geb),kinderlieb(K_lieb)
{

}

bool Shetlandpony::istKinderlieb()
{
    return kinderlieb;
}

bool Shetlandpony::isReitbar(int x)
{
    //ist Reitbar
    if(x>=5 && x<=12){
        //KinderLieb
        if(x<=8 && !istKinderlieb() ){
            cout<<"Pony ist nicht Kinderlieb fuer das maximal 8 jahre Alt"<<endl;
            return false;
        }else if((x<=8 && istKinderlieb())|| x>8){
            return true;
        }
    }else{
        cout<<"Shetlandpony Alt muss zwischen  5 und 12 sein"<<endl;
        return false;
    }
    return false;

}

void Shetlandpony::zeigeInfo()
{
    Pony::zeigeInfo();
    if(this->istKinderlieb()) ExtraFunktionen::Ausgabe("          y");
    else ExtraFunktionen::Ausgabe("          n");
    //cout<<endl;

}


