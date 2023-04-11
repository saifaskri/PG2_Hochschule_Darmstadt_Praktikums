#include "ponyhof.h"
#include "islandpferd.h"
#include "shetlandpony.h"

Ponyhof::Ponyhof()
{

}

void Ponyhof::ponyAnlegen(){

    int rasse;
    int geburtsJahr;
    string name;
    char yesNo_var_tmp;
    bool yesNo;
    bool gespeichert = true;

    while(true){
        cout<<"Welche Rasse soll eingestellt werden? [0  Isi | 1  Shetty]:"<<endl;
        cin>>rasse;
        if(rasse == 0 || rasse == 1 ){
            break;
        }
    }


    cout<<"Geburtsjahr?"<<endl;
    cin>>geburtsJahr;

    cout<<"Name"<<endl;
    cin>>name;

    while(true){

        if(rasse==0){
            cout<<"Ekzemer [y/n]"<<endl;
        }else if(rasse==1){
            cout<<"kinderlieb? [y/n]"<<endl;
        }

        cin>>yesNo_var_tmp;

        if(yesNo_var_tmp == 'y' || yesNo_var_tmp == 'Y' ){
           yesNo = true;
           break;
        }else if(yesNo_var_tmp == 'n' || yesNo_var_tmp == 'N' ){
           yesNo= false;
           break;
        }
    }

    cout<<"check"<<endl;

    if(rasse==0){
        Pony *Isi = new Islandpferd(name,geburtsJahr,yesNo);
        gespeichert = einstellen(Isi);
    }else if(rasse==1){
        Pony *Shetty= new Shetlandpony(name,geburtsJahr,yesNo);
        gespeichert= einstellen(Shetty);

    }

    if(gespeichert==true){
        cout<<"Pony wurde eingefuegt"<<endl;
    }else{
        cout<<"Leider Voll"<<endl;
    }



}



void Ponyhof::userDialog()
{
    int WHAL;

    while(true){
        cout<<"1 Pony einstellen"<<endl;
        cout<<"2 Pony zum Reiten holen"<<endl;
        cout<<"3 Ponys kontrollieren"<<endl;
        //cout<<"4 Ponys ausgeben"<<endl;
        cout<<"0 Programm beenden"<<endl;
        cin>>WHAL;
        switch (WHAL) {
        case 1:
            ponyAnlegen();
            break;
        case 2:

            break;
        case 3:

            break;
//        case 4:
//            zeigeInfo();
//            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Ungueltige Eingabe !"<<endl;
            break;
        }
    }

}
