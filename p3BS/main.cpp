//#include <iostream>

//#include "cpu.h"

//using namespace std;


//int main()
//{
//    CPU c = CPU();

//    c.schedule();


//    return 0;
//}



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>

#define PROCESS_PATH "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\p3BS\\process\\"

using namespace std;

struct Process {
    std::string programName;
    std::vector<std::string> instructions;
    int accumulator;
    int programCounter;
};

std::deque<Process> readyQueue;

void loadProgram(const std::string& programName, Process& process) {
    std::ifstream programFile(PROCESS_PATH+programName);

    if (!programFile.is_open()){
        cout << "Failed to open file " <<PROCESS_PATH+programName<<endl;
        return ;
    }

    std::string instruction;

    while (std::getline(programFile, instruction)) {
        process.instructions.push_back(instruction);
    }

    process.programName = programName;
    process.accumulator = 0;
    process.programCounter = 0;
}

void executeProgram(Process& process) {
    while (process.programCounter < process.instructions.size()) {
        const std::string& instruction = process.instructions[process.programCounter];

        char command = instruction[0];

        std::cout<<process.programName<<std::endl;

        switch (command) {
            case 'L':
                process.accumulator = std::stoi(instruction.substr(2));
                break;
            case 'A':
                process.accumulator += std::stoi(instruction.substr(2));
                break;
            case 'S':
                process.accumulator -= std::stoi(instruction.substr(2));
                break;
            case 'P':
                // Simulate I/O operation (blocking)
                //std::cout << "Process " << process.programName << " blocked for I/O." << std::endl;
                //return;
            break;
            case 'X': {
                Process newProcess;
                loadProgram(instruction.substr(2), newProcess);
                readyQueue.push_back(newProcess);
                break;
            }
            case 'Z':
                //std::cout << "Process " << process.programName << " terminated." << std::endl;
                return;
            default:
                std::cout << "Invalid instruction: " << instruction << std::endl;
        }

        process.programCounter++;
    }
}

void schedule() {
    while (!readyQueue.empty()) {
        Process process = readyQueue.front();
        readyQueue.pop_front();

        std::cout << "Executing process: " << process.programName << std::endl;
        executeProgram(process);
    }
}

int main() {
    Process initProcess;
    loadProgram("init", initProcess);
    readyQueue.push_back(initProcess);

    schedule();

    return 0;
}
