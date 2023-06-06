#include "dateiverarbeitung.h"
using namespace std ;

DateiVerarbeitung::DateiVerarbeitung()
{

}


string getFileExtension(const string& filename) {
    size_t dot_pos = filename.find_last_of(".");
    if (dot_pos != string::npos) {
        return filename.substr(dot_pos + 1);
    }
    return "";
}

void DateiVerarbeitung::Read(string filename,char delim ,int startingFrom){

    string line;
    string token;
    int currentLine=0;
    ifstream inputFile(getPROJECT_PATH()+filename,ios::in);

       if (!inputFile.is_open()) {
           cerr << "Failed to open file" << endl;
           return ;
       }

       while (getline(inputFile, line)) {

         //get ride of the spaces at the end of the Instruction
//         size_t lastNonSpace = Instruction.find_last_not_of(" ");
//         string TrammedInstruction = Instruction.substr(0, lastNonSpace + 1);
           if(!(currentLine>=startingFrom)){
               cout<<"We skipped the line number "<<currentLine<<endl;
               currentLine++;
               continue;
           }



            Pony_Struktur *p = new Pony_Struktur();
            istringstream data(line);

            getline(data,token,delim);
            p->rasse = token;

            getline(data,token,delim);
            p->name = token;

            getline(data,token,delim);
            p->geburtsJahr = stoi(token);


            getline(data,token,delim);
            p->yesNo = token[0] ;

            //push in Vector
            v.push_back(p);
            //increment the Current Line
            currentLine++;
        }//end Reading the File

       //close file
       inputFile.close();

       for (int i = 0; i < v.size(); ++i) {
           cout<< v[i]->rasse<<endl;
           cout<< v[i]->name<<endl;
           cout<< v[i]->geburtsJahr <<endl;
           cout<< v[i]->yesNo<<endl;
       }

}

void DateiVerarbeitung::WriteinCSV(string filename)
{

}

void DateiVerarbeitung::writeBin(string filename)
{
    std::ofstream output_file(getPROJECT_PATH()+"output23.bin",ios::out| ios::binary);

     if (!output_file.is_open()) {
       std::cerr << "Could not open output file!" << std::endl;
       return ;
     }

     for (int i = 0; i < v.size(); ++i) {

         output_file << v[i]->rasse<<" ";
         output_file << v[i]->name<<" ";
         output_file << v[i]->geburtsJahr<<" ";
         output_file << v[i]->yesNo<<" \n";

     }

cout<<"done";
     output_file.close(); // close the file
}












string DateiVerarbeitung::getPROJECT_PATH() const
{
    return PROJECT_PATH;
}



