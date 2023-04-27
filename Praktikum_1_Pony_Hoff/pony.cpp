#include "pony.h"
#include "islandpferd.h"
#include "shetlandpony.h"

Pony::Pony():ort(0,0){

}

Pony::~Pony()
{
    if(this!=nullptr)
    delete this;
}

Pony::Pony(string name, int gebutsJahr):gebutsJahr(gebutsJahr),name(name),ort(0,0)
{

}

Pony::Pony(string name, int gebutsJahr, float x, float y):gebutsJahr(gebutsJahr),name(name),ort(x,y)
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

void Pony::setzePos(const Position &pos)
{
    ort.x =  pos.x;
    ort.y = pos.y;
}

bool Pony::istReitbar(int x)
{
    Islandpferd *Isl;
    Shetlandpony *Shet;

    if((Isl=dynamic_cast<Islandpferd*>(this))){

        if(Isl->isReitbar(x))
            return true;
        else
            return false;
//if(x<=10){
//   return true;
//}else{
//   cout<<"Islandpferd Alt muss unter 10 sein"<<endl;
//   return false;
//}
    }else if((Shet=dynamic_cast<Shetlandpony*>(this))){
        if(Shet->isReitbar(x))
            return true;
        else
            return false;
////ist Reitbar
//if(x>=5 && x<=12){
//    //KinderLieb
//    if(x<=8 && !Shet->istKinderlieb() ){
//        cout<<"Pony ist nicht Kinderlieb fuer das maximal 8 jahre Alt"<<endl;
//        return false;
//    }else if((x<=8 && Shet->istKinderlieb())|| x>8){
//        return true;
//    }
//}else{
//    cout<<"Shetlandpony Alt muss zwischen  5 und 12 sein"<<endl;
//    return false;
//}

    }

    return true;
}

void Pony::zeigeInfo()
{
    ExtraFunktionen::Ausgabe(this->gibName());
    ExtraFunktionen::Ausgabe( to_string( this->gibgebutsJahr()));
    if((this->ort.x*100000) != 0 || (this->ort.y*10000) != 0 ){
        ExtraFunktionen::Ausgabe(to_string(this->ort.x));
        ExtraFunktionen::Ausgabe(to_string(this->ort.y));
    }
}

