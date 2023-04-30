//#include <iostream>
//#include <fstream>

//using namespace std;

//struct Studi {
//    string name;
//    int alter;
//    float note;
//};

//int main() {
//    Studi teilnehmer[] = {
//        {"Max", 22, 1.3},
//        {"Anna", 23, 2.0},
//        {"Peter", 21, 2.7},
//        {"Lisa", 22, 1.7},
//        {"Tom", 23, 3.0}
//    };

//    ofstream datei("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\tests\\a.txt", ios::binary); // Datei zum Schreiben öffnen

//    int index = sizeof(teilnehmer) / sizeof(Studi); // Anzahl der Strukturen im Array berechnen

//    datei.write(reinterpret_cast<char*>(&teilnehmer), sizeof(Studi) * index); // Daten in die Datei schreiben

//    datei.close(); // Datei schließen

//    return 0;
//}
#include <iostream>
#include <fstream>

using namespace std;

struct Studi {
    string name;
    int alter;
    float note;
};

//struct Studi {
//    string name;
//    int alter;
//    float note;
//};


int main() {

    Studi teilnehmer[] = {
        {"Max", 22, 1.3},
        {"Anna", 23, 2.0},
        {"Peter", 21, 2.7},
        {"Lisa", 22, 1.7},
        {"Tom", 23, 3.0}
    };

//    ofstream datei("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\tests\\a.txt", ios::binary); // Datei zum Schreiben öffnen

//    int index = sizeof(teilnehmer) / sizeof(Studi); // Anzahl der Strukturen im Array berechnen

//    datei.write(reinterpret_cast<char*>(&teilnehmer), sizeof(Studi) * index); // Daten in die Datei schreiben

//    datei.close(); // Datei schließen

    ifstream file("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\tests\\a.txt", ios::binary);

    if (!file) {
        cerr << "Could not open file!" << endl;
        return 1;
    }

    Studi s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Studi))) {
        cout << "ID: " << s.alter << ", Name: " << s.name << ", Grade: " << s.note << endl;
    }

    file.close();


    return 0;
}


//FILE* fp = fopen("C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\tests\\a.txt", "r");








