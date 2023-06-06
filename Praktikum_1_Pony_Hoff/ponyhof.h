#ifndef PONYHOF_H
#define PONYHOF_H

#include <iostream>
#include "stall.h"
#include <vector>
#include <fstream>
#include <cctype>
#include <cstring>

#define  PROJECT_PATH "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\Praktikum_1_Pony_Hoff\\"
using namespace std;



class Ponyhof
{
public:
    Ponyhof(int argc, char *argv[]);
    ~Ponyhof();
    void userDialog();
    void ponyAnlegen();
    void ponyHolen(string name);
    void feierabend();
    vector<string> explode(string x,char seperator=' ');
private:
    Stall stallung;
    vector<Pony*> beimReiten;
    Weide weide;
};

#endif // PONYHOF_H
