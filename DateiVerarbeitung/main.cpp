#include <iostream>
#include"dateiverarbeitung.h"

using namespace std;




int main()
{
    DateiVerarbeitung file;

    file.Read("ponys.txt",',',1);
    cin.get();

    return 0;
}

