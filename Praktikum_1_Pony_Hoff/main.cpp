#include <iostream>
#include "ponyhof.h"

using namespace std;


int ponyHufe( unsigned numPonys){



    if(numPonys == 0){
       return 0 ;
    }

    return ponyHufe(numPonys-1) + 4 ;


};

int main()
{

    unsigned NumberHufen = 0;
    NumberHufen = ponyHufe(7);
    //cout << NumberHufen<< endl;

    Ponyhof p ;
    p.userDialog();


    return 0;
}
