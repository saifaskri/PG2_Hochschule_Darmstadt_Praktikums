//#include "cpu.h"

//using namespace std;

//CPU::CPU()
//{
//    //static int counter = 0  ;
//    Process initProcess;
//    loadProgram("init", initProcess);
//    readyQueue.push_back(initProcess);

//}

//void CPU::loadProgram(const string& programName, Process& process){
//    //Process::counter++;
//    ifstream programFile(PROCESS_PATH+programName,ios::in);

//        string instruction;

//        while (getline(programFile, instruction)) {
//            process.instructions.push_back(instruction);
//        }

//        process.programName = programName;
//        process.accumulator = 0;
//        process.programCounter = 0;
//        //process.ID = Process::counter;
//    programFile.close();
//}

//void CPU::executeProgram(Process &process){

//    while (process.programCounter < process.instructions.size()) {
//      const std::string& instruction = process.instructions[process.programCounter];
//      char command = instruction[0];


//      switch (command) {
//          case 'L':
//              process.accumulator = stoi(instruction.substr(2));
//              break;
//          case 'A':
//              process.accumulator += stoi(instruction.substr(2));
//              break;
//          case 'S':
//              process.accumulator -= stoi(instruction.substr(2));
//              break;
//          case 'P':
//              // Simulate I/O operation (blocking)
//              cout << "Process " << process.programName << " blocked for I/O." << endl;
//              //return;
//          case 'X': {
//              Process newProcess;
//              loadProgram(instruction.substr(2), newProcess);
//              readyQueue.push_back(newProcess);
//              break;
//          }
//          case 'Z':
//              std::cout << "Process " << process.programName << " terminated." << std::endl;
//              return;
//          default:
//              std::cout << "Invalid instruction: " << instruction << std::endl;
//      }

//      process.programCounter++;
//  }


//}


//void CPU::schedule() {
//    while (!readyQueue.empty()) {
//        Process process = readyQueue.front();
//        readyQueue.pop_front();

//        std::cout << "Executing process: " << process.programName << std::endl;
//        executeProgram(process);
//    }
//}
