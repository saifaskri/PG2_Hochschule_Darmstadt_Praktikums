#include "ponyhof.h"
#include "islandpferd.h"
#include "shetlandpony.h"



vector<string> Ponyhof::explode(string x,char seperator){
    string word="";
    vector<string> v;
    for (size_t i = 0; i < x.length(); ++i) {


        if(x[i]!=seperator){
            word += x[i];
        }else{
            v.push_back(word);
            word="";
        }
    }
    v.push_back(word);
    return v;
}

Ponyhof::Ponyhof():weide()
{

    //Die Weide beginnt bei Position Pw (xw, yw) und ist 𝑙𝑙𝑙𝑙𝑙𝑙𝑙𝑙𝑙𝑙𝑙𝑙 × 𝑏𝑏𝑏𝑏𝑏𝑏𝑏𝑏𝑏𝑏𝑏𝑏 groß (vgl. Abbildung). Um Pi im
    //Weidebereich von (xw, yw) bis (xw+ breite, yw+ laenge) zu erhalten, gehen Sie wie folgt vor, wobei Sie
    //die zur Umsetzung benötigten Variablen zur Vereinfachung im Code als Konstanten festlegen dürfen:
    //• Zuerst für Position Pi zwei Zufallszahlen zx, zy bestimmen2
    //• Beide je durch RAND_MAX teilen, um in Bereich [0, 1] umzurechnen, damit gilt: zx‘, zy‘ ∈ [0, 1]



//    of myfile;
//    myfile.open ("ponys.txt", ios::out | ios::app | ios::binary);

    char YesNo;
    bool YesNo_bool;
    int Geburtsjahr;
    string Name;
    string Rasse;
    vector<string> Attribute;
    string line;
    bool gespeichert;

    ifstream myfile ("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\Praktikum_1_Pony_Hoff\\ponys.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            istringstream data(line);
            data>> Rasse>> Name>> Geburtsjahr>> YesNo;

            if(YesNo=='N'||YesNo=='n'){YesNo_bool=false;
            }else if (YesNo=='Y'||YesNo=='y'){YesNo_bool = true;
            }else{cout<<"Fehler steht in File"<<endl;return;}

            if(Rasse=="Islandpferd"){
                Pony *Isi = new Islandpferd(Name,Geburtsjahr,YesNo_bool);
                gespeichert = stallung.einstellen(Isi);
            }else if(Rasse=="Shetlandpony"){
                Pony *Shetty= new Shetlandpony(Name,Geburtsjahr,YesNo_bool);
                gespeichert= stallung.einstellen(Shetty);
            }

            if(gespeichert==true){cout<<"Pony wurde eingefuegt"<<endl;
            }else{cout<<"Leider Voll"<<endl;}
        }
    myfile.close();
    }

    else cout << "Unable to open file"<<endl;

}

Ponyhof::~Ponyhof()
{
    vector<Pony *> v = stallung.getAllPonysFromPferdBoxen();
    for (size_t i = 0; i < weide.PonysInWeide.size(); ++i) {
        //cout<<weide.PonysInWeide[i]->gibName()<<endl;
        v.push_back(weide.PonysInWeide[i]);
    }
    ofstream myfile ("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\Praktikum_1_Pony_Hoff\\ponys.txt");
    if (myfile.is_open())
      {

        Islandpferd *Isl;
        Shetlandpony *shet;
        for (size_t i = 0;  i < v.size(); i++) {

            if ((Isl = dynamic_cast<Islandpferd*>(v[i]))){
                myfile <<"Islandpferd"<<" "
                <<v[i]->gibName()<<" "
                <<v[i]->gibgebutsJahr()<<" "
                <<(Isl->hatEkzem()?'y':'n')<<"\n";
            }

            else if ((shet = dynamic_cast<Shetlandpony*>(v[i]))){
                  myfile <<"Shetlandpony"<<" "
                  <<v[i]->gibName()<<" "
                  <<v[i]->gibgebutsJahr()<<" "
                  <<(shet->istKinderlieb()?'y':'n')<<"\n";
            }
        }
        myfile.close();
      }
    else cout << "Unable to open file";


        for (size_t i = 0; i < weide.PonysInWeide.size(); i++) {
            delete weide.PonysInWeide[i];
        }
       cout<<"Ponys Auf der Weide wurden geloescht"<<endl;



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
        gespeichert = stallung.einstellen(Isi);
    }else if(rasse==1){
        Pony *Shetty= new Shetlandpony(name,geburtsJahr,yesNo);
        gespeichert= stallung.einstellen(Shetty);



    }

    if(gespeichert==true){
        cout<<"Pony wurde eingefuegt"<<endl;
    }else{
        cout<<"Leider Voll"<<endl;
    }



}

void Ponyhof::ponyHolen(string name)
{
    Pony* p = stallung.herausholen(name);

    if(p!=nullptr){

        cout<<"Name des zu holenden Ponys: "<<p->gibName()<<endl;
        cout<<"Pony wird geritten"<<endl;
        beimReiten.push_back(p);

    }

}

void Ponyhof::feierabend()
{
    if(beimReiten.size()==0)
        cout<<"Feierabend! Aber kein Pony ist beim Reiten"<<endl;
    else
        cout<<"Feierabend! Alle Ponys werden zurueckgebracht......"<<endl;

    for (size_t i = 0; i <  beimReiten.size(); ++i) {
        if(stallung.einstellen(beimReiten[i])){
           cout<<beimReiten[i]->gibName()<<" ist zurueck"<<endl;
        }else
           cout<<"Fehler beim Zurückbringen der Pony in Stall(Wahrscheinlich Boxen sind alle voll)"<<endl;
    }

    for (size_t i = 0; i < beimReiten.size(); ++i) {
           beimReiten.erase(beimReiten.begin()+i);
    }

}




void Ponyhof::userDialog()
{
    int WHAL;
    string name;
    //Pony *p;
    Islandpferd *Isl;
    Shetlandpony *shet;
    string line="===============================================================================================";
    while(true){



        cout<<"1 Pony einstellen"<<endl;
        cout<<"2 Pony zum Reiten holen"<<endl;
        cout<<"3 Ponys kontrollieren"<<endl;
        cout<<"4 Ponys auf Weide schicken"<<endl;
        cout<<"0 Programm beenden"<<endl;
        cin>>WHAL;
        switch (WHAL) {
        case 1:
            ponyAnlegen();
            break;
        case 2:
            cout<<"Geben Sie den Name des Ponys ein!"<<endl;
            cin>>name;
            ponyHolen(name);
            break;
        case 3:
            //if(weide.PonysInWeide.size()==0){
                stallung.zeigeInfo();
                cout<<endl;

            //}else{

                cout<<line<<endl;
                cout<<endl;
                cout<<"Es sind "<<weide.PonysInWeide.size()<<" Ponys gerade auf der Weide"<<endl;
                cout<<endl;
                if(weide.PonysInWeide.size()!=0){
                    ExtraFunktionen::Ausgabe("Rasse");
                    ExtraFunktionen::Ausgabe("Name");
                    ExtraFunktionen::Ausgabe("Geburtsjahr");
                    ExtraFunktionen::Ausgabe("X-Koordinate");
                    ExtraFunktionen::Ausgabe("Y-Koordinate");
                    ExtraFunktionen::Ausgabe("KinderLieb/HatEkzmer");
                    cout<<endl;
                    cout<<endl;
                }

                for (size_t i = 0;  i <weide.PonysInWeide.size(); i++) {
                    if ((Isl = dynamic_cast<Islandpferd*>(weide.PonysInWeide[i]))){
                        ExtraFunktionen::Ausgabe("Islandpferd");
                        Isl->zeigeInfo();
                        cout<<endl;
                    }
                    else if ((shet = dynamic_cast<Shetlandpony*>(weide.PonysInWeide[i]))){
                        ExtraFunktionen::Ausgabe("Shetlandpony");
                        shet->zeigeInfo();
                        cout<<endl;
                    }
                }
           // }
           cout<<endl;
           cout<<line<<endl;
           cout<<endl;
           cout<<"Es werden "<<beimReiten.size()<<" Ponys gerade geritten"<<endl;
           cout<<endl;
           //if All Ponys auf der Weide, so the mittel Old wi´ll not be outputed
           if(weide.PonysInWeide.size()==0){
               cout<<"Durchschnittsalter ist "<<stallung.durchschnittsalter()<<endl;
               cout<<endl;
           }
           cout<<line<<endl;
           cout<<endl;
            break;
        case 4:
            stallung.weidegang(weide);
            break;
        case 0:
            feierabend();
            delete this;
            exit(0);
            break;
        default:
            cout<<"Ungueltige Eingabe !"<<endl;
            break;
        }
    }

}
