#ifndef PONYHOF_H
#define PONYHOF_H

#include <iostream>
#include "stall.h"
#include <vector>

using namespace std;

class Ponyhof
{
public:
    Ponyhof();
    void userDialog();
private:
    Stall stallung;
    vector<Pony*> beimReiten;
    //?????????????
    string weide;
};

#endif // PONYHOF_H
