#include "ponyhof.h"
#include "islandpferd.h"
#include "shetlandpony.h"
using namespace std;

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

char UserPromet(){
    char x;
    while(true){
        cout<<"Neu einlesen [e] oder abbrechen [a]?"<<endl;
        cin>>x;
        if(x =='E'|| x == 'A' || x =='e'|| x == 'a' ) break;
    }
    return x;
}

void ContinueOrExitProgramme(){
    char x = UserPromet();
    if(x=='a'||x=='A')
        exit(0);
}

struct Data
{
    string Rasse;
    string Name;
    string Geburtsjahr;
    char YesNo;
    bool YesNo_bool;
    Data() {}
};

ifstream openFileReadOnly(string path,string DateiName="ponys.txt",string mode="A"){


    if(mode=="A"){
        ifstream myfile (path+DateiName , std::ios::in);
        return myfile;
    }
    else{
        ifstream myfile (path+DateiName , std::ios::in | ios::binary );
        return myfile;
    }


}


void checkYesNo(Data &mydata){


    if( mydata.YesNo=='N'|| mydata.YesNo=='n')
        mydata.YesNo_bool=false;
    else if ( mydata.YesNo=='Y'|| mydata.YesNo=='y')
        mydata.YesNo_bool = true;
    else
        throw  "y/n Fehler" ;

}


void checkGeburtsJahr(Data &mydata){

   if(mydata.Geburtsjahr.length()<4)
       throw "Falsches Geburtsjahr Format less than 4";

   else{
       for (size_t i = 0; i < mydata.Geburtsjahr.length(); ++i) {
           if(!isdigit(mydata.Geburtsjahr[i])){
               throw "Falsche Geburtsjahr Format es gibt ein Buchstaben dadrinnen";
               break;
           }
    }   }
}

void checkRasse(Data mydata){

    if(mydata.Rasse!="Shetlandpony" && mydata.Rasse!="Islandpferd" )
        throw "falsche Rasse Type im Datei ";

}

bool CreateAndAddNewPony(Stall &stallung, Data mydata){
    bool gespeichert = false;

    if(mydata.Rasse=="Islandpferd"){
        Pony *Isi = new Islandpferd(mydata.Name,stoi(mydata.Geburtsjahr),mydata.YesNo_bool);
        gespeichert=stallung.einstellen(Isi);
    }
    else if(mydata.Rasse=="Shetlandpony"){
        Pony *Shetty= new Shetlandpony(mydata.Name,stoi(mydata.Geburtsjahr),mydata.YesNo_bool);
        gespeichert =  stallung.einstellen(Shetty);
    }else{
        cout<<"Fehler Wede Shetlandpony noch Islandpferd "<<endl;
        return false;
    }


    if(gespeichert)
        cout<<"Pony wurde eingefuegt"<<endl;
    else cout<<"Leider Voll"<<endl;

    return gespeichert;
}

void suspendierungsZeile(bool &FehlerInDateiGefunden,int currentZeileNummer ){
    if(FehlerInDateiGefunden){
        cout<<endl;
        cout<<"Lese Datei ab Zeile "<<currentZeileNummer<<" neu ein..."<<endl;
        cout<<endl;
        FehlerInDateiGefunden = false;
    }

}

void convertTxtToBin(){
    string line ;

    ifstream myfile = openFileReadOnly(PROJECT_PATH) ;
    ofstream binaryFile("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\Praktikum_1_Pony_Hoff\\ponys.bin", ios::binary);
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            // Öffnen der Datei im binären Schreibmodus
            line+="\n";
            if (binaryFile.is_open()) {
                // Schreiben des Texts als binäre Daten in die Datei
                binaryFile.write(line.c_str(), line.length());
                cout << "Text erfolgreich in binaere Daten konvertiert." << endl;
            } else {
                // Fehler beim Öffnen der Datei
                cout << "Fehler beim Öffnen der Datei." << endl;
                return;
            }
        }
    }
    binaryFile.close();
    myfile.close();

}

string getFileExt(char *x){
    string ext="";
    bool pointFound = false;
    for (size_t i = 0; i <strlen(x); ++i) {
        if(x[i] == '.')
            pointFound = true;
        if(pointFound)
            ext+=x[i];
    }
    return ext;
}

Ponyhof::Ponyhof(int argc, char* argv[]):weide()
{

    string mode="A";
    string DateiName;

    #ifdef WRITE_BIN
        mode = "B";
        cout << "Binary writer called...\n";
    #else
        mode = "A";
        cout << "ASCII writer called...\n";
    #endif

        // prüfe text Übergabe
    if(argc>=2){
        if(getFileExt(*(argv+1))==".txt" && mode == "B"){
            //Wiederspruch
            cout<<"WiederSpruch einmal txt Datei einaml binaer modus"<<endl;
            cout<<"Es wird Defaultmaessig gelesen (TXT)"<<endl;
            mode="A";
            DateiName = "ponys.txt";
        }else if(getFileExt(*(argv+1))==".bin" && mode == "A"){
            //Wiederspruch
            cout<<"WiederSpruch einmal bin Datei einmal Text modus"<<endl;
            cout<<"Es wird Defaultmaessig gelesen (TXT)"<<endl;
            mode="A";
            DateiName = "ponys.txt";
        }else if(getFileExt(*(argv+1))==".bin" && mode == "B"){
            mode="B";
            DateiName = *(argv+1)  ;
        }else if(getFileExt(*(argv+1))==".txt" && mode == "A"){
            mode="A";
            DateiName = *(argv+1) ;
        }
        cout<<"==========================================="<<endl;
        cout<< "uebergebenen Datei  "<<getFileExt(*(argv+1))<<" ";

    }else{
        cout<<"kein Datei wurde uebergeben"<<endl;
    }

    cout<<"Modus "<<mode<<endl;
    cout<<"==========================================="<<endl;



    string line;
    Data mydata;
    int angehalteneZeile = 0 , currentZeileNummer = 0;
    bool FehlerInDateiGefunden = false;

    convertTxtToBin();

    ifstream myfile = openFileReadOnly(PROJECT_PATH,DateiName,mode) ;
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            currentZeileNummer++;
            if(currentZeileNummer>=angehalteneZeile){
                try {

                    suspendierungsZeile(FehlerInDateiGefunden,currentZeileNummer);
                    istringstream data(line);
                    data >> mydata.Rasse >> mydata.Name >> mydata.Geburtsjahr >> mydata.YesNo;
                    checkRasse(mydata);
                    //Name Braucht Man nicht zu überprüfen?
                    checkGeburtsJahr(mydata);
                    checkYesNo(mydata);
                    CreateAndAddNewPony( stallung, mydata);

                } catch ( const char* error) {

                    cout  <<endl<<"Fehler in Zeile "<<currentZeileNummer<<" bitte korregieren!"<<endl;
                    cerr<< "Error: " << error <<endl<<endl;
                    ContinueOrExitProgramme();
                    angehalteneZeile=currentZeileNummer; currentZeileNummer=0; FehlerInDateiGefunden = true;
                    myfile = openFileReadOnly(PROJECT_PATH,DateiName,mode);

                }
            }
        }//end While Loop
        myfile.close();
    }//if file was successfuly opened
    else // file not found
        cout << "Unable to open file"<<endl;
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
