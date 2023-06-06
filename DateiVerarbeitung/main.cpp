//#include <iostream>
//#include"dateiverarbeitung.h"

//using namespace std;




//int main()
//{
//    DateiVerarbeitung file;

//    file.Read("ponys.txt",',',1);
//    cin.get();

//    return 0;
//}


#include <iostream>
#include <fstream>

const std::string PROJECT_PATH = "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\DateiVerarbeitung\\NewFileToTest\\";


// ascii zu binär umwandeln
int main() {
    std::ifstream asciiFile(PROJECT_PATH+"input.txt");  // Open ASCII input file
    std::ofstream binaryFile(PROJECT_PATH+"output.bin", std::ios::binary);  // Create binary output file

    if (!asciiFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!binaryFile) {
        std::cerr << "Failed to create output file." << std::endl;
        return 1;
    }


    char *ch = new char[20] ;
    while (asciiFile.get(*ch)) {
        std::cout<<*ch<<std::endl;
        binaryFile.write(reinterpret_cast<const char*>(ch), sizeof(ch));
    }

    asciiFile.close();


    binaryFile.close();

    std::cout << "File converted successfully." << std::endl;

    return 0;
}


// binär zu ascii umwandeln

int main1() {
    std::ifstream binaryFile(PROJECT_PATH+"input.bin", std::ios::binary);  // Open binary input file
    std::ofstream asciiFile(PROJECT_PATH+"output.txt");  // Create ASCII output file

    if (!binaryFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!asciiFile) {
        std::cerr << "Failed to create output file." << std::endl;
        return 1;
    }

    char *ch = new char[0] ;
    while (binaryFile.read(reinterpret_cast<char*>(ch), sizeof(ch))) {
        std::cout<<*ch<<std::endl;
        asciiFile << *ch;
    }

    binaryFile.close();
    asciiFile.close();

    std::cout << "File converted successfully." << std::endl;

    return 0;
}












struct Person {
    char name[50];
    int age;
    double salary;
};

int main2() {
    // Writing to a binary file
    std::ofstream outFile(PROJECT_PATH+"persons.bin", std::ios::binary | std::ios::out);
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    Person person1 = { "John Doe", 30, 5000.0 };
    Person person2 = { "Jane Smith", 25, 4500.0 };

    outFile.write(reinterpret_cast<char*>(&person1), sizeof(person1));
    outFile.write(reinterpret_cast<char*>(&person2), sizeof(person2));

    outFile.close();

    // Reading from a binary file
    std::ifstream inFile(PROJECT_PATH+"persons.bin", std::ios::binary | std::ios::in);
    if (!inFile) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return 1;
    }

    Person readPerson1;
    Person readPerson2;

    inFile.read(reinterpret_cast<char*>(&readPerson1), sizeof(readPerson1));
    inFile.read(reinterpret_cast<char*>(&readPerson2), sizeof(readPerson2));

    std::cout << "Person 1: " << readPerson1.name << ", " << readPerson1.age << ", " << readPerson1.salary << std::endl;
    std::cout << "Person 2: " << readPerson2.name << ", " << readPerson2.age << ", " << readPerson2.salary << std::endl;

    inFile.close();

    return 0;
}
