#include "stall.h"
#include "islandpferd.h"
#include "shetlandpony.h"

Stall::Stall()
{
    for (int i = 0; i < SIZE; ++i) {
        pferdeboxen[i]=nullptr;
    }
}

int Stall::belegteBoxen()
{
    int PonyZahl = 0;
    for (int i = 0; i < SIZE; ++i) {
        if(pferdeboxen[i]!=nullptr)
            PonyZahl++;
    }
    return PonyZahl;
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
    cout<<"es gibt "<<belegteBoxen()<<" Ponys im Stall gerade untergestellt "<<endl;
    cout<<endl;
    cout<<endl;

    string gap="      ";
    string line="==================================================================";

    if(getPferdeboxen_belegung()==0){
        cout<<"Pferdeboxen sind Leer"<<endl;
    }

    Islandpferd *Isl;
    Shetlandpony *shet;
    cout<<line<<endl;
    for (int i = 0;  i < getPferdeboxen_belegung(); i++) {
        if ((Isl = dynamic_cast<Islandpferd*>(pferdeboxen[i]))){
            cout<<"Islandpferd"<<gap;
            cout<< pferdeboxen[i]->gibName()<<gap;
            cout<< pferdeboxen[i]->gibgebutsJahr()<<gap;
            cout<< "Ekzemer ? "<< (Isl->hatEkzem()?'y':'n') <<endl;
        }

        else if ((shet = dynamic_cast<Shetlandpony*>(pferdeboxen[i]))){
            cout<<"Shetlandpony"<<gap;
            cout<< pferdeboxen[i]->gibName()<<gap;
            cout<< pferdeboxen[i]->gibgebutsJahr()<<gap;
            cout<< "KinderLieb ? "<< (shet->istKinderlieb()?'y':'n') <<endl;
        }

    }
    cout<<line<<endl;


}

int Stall::getPferdeboxen_belegung() const
{
    return pferdeboxen_belegung;
}

void Stall::setPferdeboxen_belegung(int newPferdeboxen_belegung)
{
    pferdeboxen_belegung = newPferdeboxen_belegung;
}
