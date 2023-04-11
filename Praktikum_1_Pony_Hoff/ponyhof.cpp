#include "ponyhof.h"

Ponyhof::Ponyhof()
{

}

void Ponyhof::userDialog()
{
    int WHAL;

    while(true){
        cout<<"1 Pony einstellen"<<endl;
        cout<<"2 Pony zum Reiten holen"<<endl;
        cout<<"3 Ponys kontrollieren"<<endl;
        cout<<"0 Programm beenden"<<endl;
        cin>>WHAL;
        switch (WHAL) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"Ungeultige Eingabe !";
            break;
        }
    }

}
