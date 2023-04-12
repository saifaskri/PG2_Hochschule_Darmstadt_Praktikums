#include "stall.h"
#include "islandpferd.h"
#include "shetlandpony.h"

Stall::Stall()
{

}

int Stall::belegteBoxen()
{

}

bool Stall::einstellen(Pony *p)
{
    if(getPferdeboxen_belegung() == SIZE - 1){
       return false;
    }

    pferdeboxen[getPferdeboxen_belegung()] = p;
    setPferdeboxen_belegung(getPferdeboxen_belegung()+1);
    return true;
}

Pony *Stall::herausholen(string name)
{
    Pony* p;

    for (int i = 0;  i < getPferdeboxen_belegung(); i++) {
        if(pferdeboxen[i]!=nullptr){
            if (pferdeboxen[i]->gibName()==name){
                p = pferdeboxen[i];
                int alt;
                cout<<"Alter des Reiters: "<<endl;
                cin>>alt;

                if(p->istReitbar(alt)){
                    pferdeboxen[i]=nullptr;
                    return p;
                }else{
                    cout<<"Pony nicht reitbar"<<endl;
                    return nullptr;
                    //:::::::::::::
                }
            }
        }
    }
    cout<<"Pony wurde nicht gefunden"<<endl;
    return nullptr;
}

float Stall::durchschnittsalter()
{

}

void Stall::weidegang()
{

}

void Stall::zeigeInfo()
{
    cout<<"okey1";
    if(getPferdeboxen_belegung()==0){
        cout<<"Pferdeboxen sind Leer"<<endl;
    }

    cout<<getPferdeboxen_belegung()<<endl;
    cout<<"okey2";
    Islandpferd *Isl;
    Shetlandpony *shet;

    for (int i = 0;  i < getPferdeboxen_belegung(); i++) {
        if ((Isl = dynamic_cast<Islandpferd*>(pferdeboxen[i]))){
            cout<< pferdeboxen[i]->gibName() <<endl;
            cout<< pferdeboxen[i]->gibgebutsJahr()<<endl;
            cout<< "Ekzemer ? "<< Isl->hatEkzem() <<endl;
        }

        else if ((shet = dynamic_cast<Shetlandpony*>(pferdeboxen[i]))){
            cout<< pferdeboxen[i]->gibName() <<endl;
            cout<< pferdeboxen[i]->gibgebutsJahr() <<endl;
            cout<< "KinderLieb ? "<< shet->istKinderlieb() <<endl;
        }

    }

}

int Stall::getPferdeboxen_belegung() const
{
    return pferdeboxen_belegung;
}

void Stall::setPferdeboxen_belegung(int newPferdeboxen_belegung)
{
    pferdeboxen_belegung = newPferdeboxen_belegung;
}
