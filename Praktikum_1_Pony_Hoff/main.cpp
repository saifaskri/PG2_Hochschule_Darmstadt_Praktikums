#include <iostream>
#include "ponyhof.h"

using namespace std;


int ponyHufe( unsigned numPonys = 20){



    if(numPonys == 0){
       return 0 ;
    }

    return ponyHufe(numPonys-1) + 4 ;


};

int main(int argc, char* argv[])
{

//    cout<<"Number of Parameters is "<<argc<<endl;
//    for(int i =0 ;i<argc;i++){
//        cout<<"Parameter Nr: "<<i<<" "<<*(argv+i)<<endl;
//    }

//    exit(0);

//    unsigned NumberHufen = 0;
//    NumberHufen = ponyHufe(7);
    //cout << NumberHufen<< endl;

    Ponyhof p(argc, argv) ;
    p.userDialog( );


    return 0;
}
