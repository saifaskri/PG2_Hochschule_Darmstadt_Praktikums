#ifndef DATEIVERARBEITUNG_H
#define DATEIVERARBEITUNG_H
#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
using namespace std;

struct Pony_Struktur{
    string rasse;
    string name ;
    int geburtsJahr;
    char yesNo;
    Pony_Struktur(){};
    Pony_Struktur(string rasse , string name,  int geburtsJahr ,char yesNo ):rasse(rasse),name(name),
        geburtsJahr(geburtsJahr),yesNo(yesNo){};
};

class DateiVerarbeitung
{
public:
    DateiVerarbeitung();
    void Read(string filename, char delim, int startingFrom);

    void WriteinCSV(string filename);
    void writeBin(string filename);


    std::string getPROJECT_PATH() const;

    vector<Pony_Struktur*> v;

private:
    const std::string PROJECT_PATH = "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\DateiVerarbeitung\\";
};

#endif // DATEIVERARBEITUNG_H














//std::ios::in: Open the file for reading.
//std::ios::binary: Open the file in binary mode, which disables any text processing and treats the file as a binary data stream. This can be useful when reading non-text files such as images or audio.
//std::ios::ate: Set the initial position to the end of the file. This can be useful when you want to determine the size of the file before reading its contents.
//std::ios::app: Append to the end of the file instead of overwriting its contents.
//std::ios::trunc: Truncate the file if it already exists. This can be useful when you want to overwrite the file with new data.
