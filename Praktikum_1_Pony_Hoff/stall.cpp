#include "stall.h"
#include "islandpferd.h"
#include "shetlandpony.h"

vector<Pony*> AllePonysImPonyHof;

Stall::Stall()
{
    for (int i = 0; i < SIZE; ++i) {
        pferdeboxen[i]=nullptr;
    }
}

Stall::~Stall()
{

    for (int i = 0; i < SIZE; i++) {
       delete pferdeboxen[i];
    }
    cout<<"Ponys im Stall wurden geloescht"<<endl;

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

    //ALL Ponys sind Hier
    AllePonysImPonyHof.push_back(p);

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
    float Durchschnittsalter = 0.0;

    for (int i = 0;  i < SIZE; i++) {
        if(pferdeboxen[i]!=nullptr)
            Durchschnittsalter+= berechneJahr() - pferdeboxen[i]->gibgebutsJahr();
    }

    return Durchschnittsalter/getPferdeboxen_belegung();
}

void Stall::weidegang(Weide &weide)
{
    srand(time(NULL));

    float x;
    float y;

    for (int i = 0; i < SIZE; ++i) {
        if(pferdeboxen[i]!=nullptr){
            x = (float)rand()/RAND_MAX;
            y = (float)rand()/RAND_MAX;


            Position pos( ( x * weide.Breite + weide.Px ) , (y * weide.Lange + weide.Py) );
            pferdeboxen[i]->setzePos(pos);

            weide.PonysInWeide.push_back(pferdeboxen[i]);
            pferdeboxen[i]=nullptr;
        }
    }
}

void Stall::zeigeInfo()
{
    int ZahlDerPonysImStall = 0 ;
    for (int i = 0; i < SIZE; i++) {
        if(pferdeboxen[i] != nullptr)
            ZahlDerPonysImStall++;
    }

    cout<<"es gibt "<<ZahlDerPonysImStall<<" Ponys im Stall gerade untergestellt "<<endl;
    cout<<endl;
    cout<<endl;

    string gap="      ";
    string line="===============================================================================================";
    cout<<line<<endl;
    cout<<endl;
    if(ZahlDerPonysImStall==0){
        cout<<"es gibt keinen Pony im Stall"<<endl;
        //cout<<endl;
        return;
    }else{
        cout<<"Pony im Stall sind : "<<endl;
        cout<<endl;
        ExtraFunktionen::Ausgabe("Rasse");
        ExtraFunktionen::Ausgabe("Name");
        ExtraFunktionen::Ausgabe("Geburtsjahr");
        ExtraFunktionen::Ausgabe("KinderLieb/HatEkzmer");
        cout<<endl;
        cout<<endl;
    }

    Islandpferd *Isl;
    Shetlandpony *shet;

    for (int i = 0;  i <SIZE; i++) {
        if ((Isl = dynamic_cast<Islandpferd*>(pferdeboxen[i]))){
            ExtraFunktionen::Ausgabe("Islandpferd");
            pferdeboxen[i]->zeigeInfo();
            cout<<endl;
        }

        else if ((shet = dynamic_cast<Shetlandpony*>(pferdeboxen[i]))){
            ExtraFunktionen::Ausgabe("Shetlandpony");
            shet->zeigeInfo();
            cout<<endl;
        }
    }
}

int Stall::berechneJahr()
{
    time_t seconds = time(NULL);
    //cout<<(seconds/(3600*24*365,25)-1970)<<endl;
    return 2023;
}

vector<Pony *> Stall::getAllPonysFromPferdBoxen()
{
    vector<Pony *> v;

    for (int i = 0;  i < SIZE; i++) {
        if(pferdeboxen[i]!=nullptr)
       v.push_back(pferdeboxen[i]);
    }

    return v;
}

int Stall::getPferdeboxen_belegung() const
{
    return pferdeboxen_belegung;
}

void Stall::setPferdeboxen_belegung(int newPferdeboxen_belegung)
{
    pferdeboxen_belegung = newPferdeboxen_belegung;
}
