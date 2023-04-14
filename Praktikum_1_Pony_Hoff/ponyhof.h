#ifndef PONYHOF_H
#define PONYHOF_H

#include <iostream>
#include "stall.h"
#include <vector>
#include <fstream>

using namespace std;

class Ponyhof : public Stall
{
public:
    Ponyhof();
    void userDialog();
    void ponyAnlegen();
    void ponyHolen(string name);
    void feierabend();
    vector<string> explode(string x,char seperator=' ');
private:
    Stall stallung;
    vector<Pony*> beimReiten;
    //?????????????
    string weide;
};

#endif // PONYHOF_H
