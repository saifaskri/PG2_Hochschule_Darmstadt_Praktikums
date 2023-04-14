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

Ponyhof::Ponyhof()
{
//    ofstream myfile;
//    myfile.open ("ponys.txt", ios::out | ios::app | ios::binary);

    char YesNo;
    bool YesNo_bool;
    int Geburtsjahr;
    string Name;
    string Rasse;
    vector<string> Attribute;
    int zaehler;
    string line;
    bool gespeichert;

    ifstream myfile ("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\Praktikum_1_Pony_Hoff\\ponys.txt");
    if (myfile.is_open()){
    while ( getline (myfile,line) ){
      Attribute = explode(line);

      zaehler = -1;
      for (size_t i = 0; i < Attribute.size(); i++) {

                Rasse = Attribute[i];
                Name = Attribute[i+1];
                Geburtsjahr = stoi (Attribute[i+2]);
                YesNo =  Attribute[i+3][0];
                if(YesNo=='N'||YesNo=='n'){
                    YesNo_bool=false;
                }else if (YesNo=='Y'||YesNo=='y'){
                    YesNo_bool = true;
                }else{
                    cout<<"Fehler steht in File"<<endl;
                    return;
                }
                i+=4;


                if(Rasse=="Islandpferd"){
                    Pony *Isi = new Islandpferd(Name,Geburtsjahr,YesNo_bool);
                    gespeichert = einstellen(Isi);
                }else if(Rasse=="Shetlandpony"){
                    Pony *Shetty= new Shetlandpony(Name,Geburtsjahr,YesNo_bool);
                    gespeichert= einstellen(Shetty);

                }

                if(gespeichert==true){
                    cout<<"Pony wurde eingefuegt"<<endl;
                }else{
                    cout<<"Leider Voll"<<endl;
                }
      }
    }
    myfile.close();
    }

    else cout << "Unable to open file"<<endl;

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

void Ponyhof::ponyHolen(string name)
{
    Pony* p = herausholen(name);

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

    for (size_t i = 0; i < beimReiten.size(); ++i) {
        if(einstellen(beimReiten[i])){
           cout<<beimReiten[i]->gibName()<<" ist zurueck"<<endl;
           beimReiten.erase(beimReiten.begin()+i);
        }else
           cout<<"Fehler beim Zurückbringen der Pony in Stall(Wahrscheinlich Boxen sind alle voll)"<<endl;
    }

    for (size_t i = 0; i < beimReiten.size(); ++i) {
           cout<<beimReiten[i]->gibName()<<" is"<<endl;
      }
}



void Ponyhof::userDialog()
{
    int WHAL;
    string name;
    Pony *p;
    while(true){
        cout<<"1 Pony einstellen"<<endl;
        cout<<"2 Pony zum Reiten holen"<<endl;
        cout<<"3 Ponys kontrollieren"<<endl;
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
               zeigeInfo();
               cout<<"es werden "<<beimReiten.size()<<" Ponys gerade geritten "<<endl;
               cout<<endl;
               cout<<endl;
            break;
        case 0:
            feierabend();
            //exit(0);
            break;
        default:
            cout<<"Ungueltige Eingabe !"<<endl;
            break;
        }
    }

}
