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
    unsigned NumberHufe = 0;
    NumberHufe = ponyHufe(7);
    cout << NumberHufe<< endl;

    Ponyhof *p = new Ponyhof();
    p->userDialog();


    return 0;
}
