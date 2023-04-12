#include "pony.h"
#include "islandpferd.h"
#include "shetlandpony.h"

Pony::Pony():ort(0,0){

}

Pony::Pony(string name, int gebutsJahr):gebutsJahr(gebutsJahr),name(name),ort(0,0)
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
    Islandpferd *Isl;
    Shetlandpony *Shet;

    if((Isl=dynamic_cast<Islandpferd*>(this))){
       if(x<=10){
           return true;
       }else{
           return false;
       }
    }else if((Shet=dynamic_cast<Shetlandpony*>(this))){



        //ist Reitbar
        if(x>=5 && x<=12){
            //KinderLieb
            if(x<=8 && !Shet->istKinderlieb() ){
                cout<<"Pony ist nicht Kinderlieb für das maximal 8 jahre Alt"<<endl;
                return false;
            }else if((x<=8 && Shet->istKinderlieb())||x>8){
                return true;
            }

        }else{
            return false;
        }
    }

    return true;
}

void Pony::zeigeInfo()
{

}

