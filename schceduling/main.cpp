#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <iomanip>

#define PROCESS_PATH "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\p3BS\\process\\"

#define SPACE_BETWEEN_WORDS 15
#define SEPARATOR ' '

#define READY "ready"
#define TERMINATED "terminated"
#define WAITING "waiting"
#define WAITING_FOR_CHILD_PROCESS "waiting_for_child Process"


using namespace std;

static int IDcounter = 0;
static bool showUpBar = false;

void Buchhaltung_UpBar(){
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Takt";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "PID";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Prozess";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "PC";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Akk";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "E/A";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Befehl"<<endl;;

    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "----";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "---";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-------";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "--";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "---";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "---";
    cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-------"<<endl;;
}


struct Process {
    string programName;
    vector<string> instructions;
    int accumulator;
    int programCounter;
    int id = -1;
    int waitingsCPU_TAKT = 4;
    //ein neuer Prozess ist immer beim erzeugen bereit ausgeführt zu werden.
    string status = "ready";
};




struct IOUnit{

    deque <Process*> waitingQueue;

    int WaitingsCPU_TAKTs = 4 ;

    void handelProcessesInWaitingMode(){

        if(!waitingQueue.empty()){
            this->WaitingsCPU_TAKTs--;
            if(WaitingsCPU_TAKTs == 0){

                // set The Process ready
                waitingQueue.front()->status = READY;

                //set that for the next Process
                WaitingsCPU_TAKTs = 4;

            }
        }

    };


    IOUnit(){};
};



Process* loadProcessAndCreateNewProcess(const std::string& programName) {

    Process* newProcess = new Process();

    //start read Programm
        ifstream programFile(PROCESS_PATH + programName);
        if (!programFile.is_open()){
            cout << "Failed to Load Process " << programName <<endl;
            //check if id = -1 bevor to add this Process to the ReadyQueue
            //because here there is no new Process just don't add it
            return newProcess ;
        }
        string instruction;
        while (getline(programFile, instruction)) {
            newProcess->instructions.push_back(instruction);
        }
        programFile.close();
    //end read Programm

    //start set Default Values for a new Process
        newProcess->programName = programName;
        newProcess->accumulator = 0;
        newProcess->programCounter = 0;
        newProcess->id = IDcounter;
        newProcess->status = "ready";
    //end set Default Values for a new Process


    //static counter
    IDcounter++;

    //check if id = -1 bevor to add this Process to the ReadyQueue
    //because here there is no new Process just don't add it
    return newProcess;
}



struct CPU{

    int ACC;
    int PC;
    string IR;
    int CPU_TAKT = 0;
    Process  *executed_Process;

    IOUnit io_unit;
    deque <Process*> readyQueue;


    CPU() {
        Process *initProcess = new Process();
        executed_Process = new Process();
        initProcess = loadProcessAndCreateNewProcess("init");
        readyQueue.push_back(initProcess);
    }

    void Buchhaltung(){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << CPU_TAKT;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << executed_Process->id;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << executed_Process->programName;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << PC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << ACC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << 60 ;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << executed_Process->instructions[PC] ;
       cout<<endl<<endl;
    };

    void Buchhaltung_no_Process(){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << CPU_TAKT;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "---";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << PC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << ACC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << -io_unit.WaitingsCPU_TAKTs  ;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "wait => "+io_unit.waitingQueue.front()->programName;
       cout<<endl<<endl;
    };


    void executeProgram() {

        if(!showUpBar){
            Buchhaltung_UpBar();
            showUpBar = true;
        }

        //CPU Program Counter eqauls programCounter of the Process
        PC = executed_Process->programCounter;
        //CPU accumulator eqauls accumulator of the Process
        ACC = executed_Process->accumulator;

        while (PC < executed_Process->instructions.size()) {

            const string& instruction = executed_Process->instructions[PC];
            char command = instruction[0];

            Buchhaltung();
            CPU_TAKT++;
            PC++;

            switch (command) {
                case 'L':
                    ACC = stoi(instruction.substr(2));
                    break;
                case 'A':
                    ACC += stoi(instruction.substr(2));
                    break;
                case 'S':
                    ACC -= stoi(instruction.substr(2));
                    break;
                case 'P':
                    //Simulate I/O operation (blocking)
                    //cout << "Process " << process->programName << " blocked for I/O." << std::endl;
                    executed_Process->status = WAITING;
                    break;
                case 'X': {
                        Process *newProcess = new Process();
                        newProcess = loadProcessAndCreateNewProcess(instruction.substr(2));
                        //check if id = -1 bevor to add this Process to the ReadyQueue
                        //because here there is no new Process just don't add it
                        if(newProcess->id != -1){
                            readyQueue.push_back(executed_Process);
                            readyQueue.push_back(newProcess);
                            executed_Process->status = WAITING_FOR_CHILD_PROCESS;
                        }
                        //else programm will continue normaly
                        break;
                    }
                case 'Z':
                    std::cout << "Process " << executed_Process->programName << " terminated."" "<<executed_Process->id  << std::endl<<endl;
                    executed_Process->status = TERMINATED;
                    break;
                default:
                    std::cout << "Invalid instruction: " << instruction << std::endl;
                    break;

            }

            //check the WaitingsQueue for each Takt
            io_unit.handelProcessesInWaitingMode();

            // Process is waitting it's will go to the (waiting / Blocked) Queue => immer fügen wir am Hinten hinzu
            if(executed_Process->status == WAITING){

                // save the Acc And PC in The Process befor the Process leaves the CPU
                executed_Process->programCounter = PC;
                executed_Process->accumulator = ACC;

                // move the process from the CPU to the waitingQueue
                io_unit.waitingQueue.push_back(executed_Process);
                return;
            }


            // Process is waitting for the child process to be done
            if(executed_Process->status == WAITING_FOR_CHILD_PROCESS){


                // save the Acc And PC in The Process befor the Process leaves the CPU
                executed_Process->programCounter = PC;
                executed_Process->accumulator = ACC;

                //process noch mal bereit machen
                executed_Process->status = READY;

                return;
            }



            // proccess is done
            if(executed_Process->status == TERMINATED){
                // process geht von dem CPU raus (beendet)
               return;
            }
        }


        // the Programm Counter in bigger than the size the the Instruction of the Process it's self
        //das darf nie geschehen aber falls ja passiert dann beenden wir auch den Prozess
        return;

    }

    void schedule() {

        while (!readyQueue.empty() || !io_unit.waitingQueue.empty()) {

                //move ready Process to the front of CPU
                if(!io_unit.waitingQueue.empty()){
                    if(io_unit.waitingQueue.front()->status == READY){
                        // move Process from waitingQueue to readyQueue
                        readyQueue.push_back(io_unit.waitingQueue.front());
                        //delete the Process form waiting Queue
                        io_unit.waitingQueue.pop_front();
                    }
                }

                //execute ready process
                if(!readyQueue.empty()){

                    executed_Process = readyQueue.back();
                    readyQueue.pop_back();
                    std::cout << "Executing process: " << executed_Process->programName<<" "<<executed_Process->id << std::endl<<endl;
                    executeProgram();
                }

                //if readyQueue is empty
                if(readyQueue.empty()){

                        if(!io_unit.waitingQueue.empty()){
                            Buchhaltung_no_Process();
                        }

                        CPU_TAKT++;
                        //check the WaitingsQueue for each Takt
                        io_unit.handelProcessesInWaitingMode();

                }



        }



    }

};





int main()
{



    CPU cpu = CPU();

    cpu.schedule();

    exit(0);  // Exit the program

    return 0;
}










//void schedule() {

//    while (!readyQueue.empty() || !waitingQueue.empty()) {

//        Process *process = new Process();

//        process = readyQueue.back();

//        readyQueue.pop_back();

//        //std::cout << "Executing process: " << process->programName << std::endl;
//        executeProgram(process);

//    }
//}



//class IOUnits {
//private:
//    deque<int> blockedProcesses;

//public:
//    void blockProcess(int processID) {
//       // blockedProcesses.push(processID);
//    }

//    void unblockProcess() {
//        if (!blockedProcesses.empty()) {
//            int processID = blockedProcesses.front();
//            //blockedProcesses.pop();
//            // Hier können weitere Aktionen zur Freigabe des Prozesses durchgeführt werden
//        }
//    }
//};



//void executeProgram(Process * process) {

//    if(!showUpBar){
//        Buchhaltung_UpBar();
//        showUpBar = true;
//    }

//    while (process->programCounter < process->instructions.size()) {



//        // proccess is done
//        if(process->status == TERMINATED){
//            // process geht von dem CPU raus (beendet)
//           return;
//        }

//        //Process is waitting
//        // go to the waiting / Blocked Queue => immer fügen wir am Hinten hinzu
//        if(process->status == WAITING){
//            //waitingQueue.push_back(process);
//            //return;
//        }

//        // ansonsten wird dem Process den CPU zugewiessen bekommen



//        const std::string& instruction = process->instructions[process->programCounter];
//        char command = instruction[0];
//        Buchhaltung(process);
//        process->programCounter++;


//        switch (command) {
//            case 'L':
//                process->accumulator = std::stoi(instruction.substr(2));
//                CPU_TAKT++;
//                break;
//            case 'A':
//                process->accumulator += std::stoi(instruction.substr(2));
//                CPU_TAKT++;
//                break;
//            case 'S':
//                process->accumulator -= std::stoi(instruction.substr(2));
//                CPU_TAKT++;
//                break;
//            case 'P':
//                //Simulate I/O operation (blocking)
//                //cout << "Process " << process->programName << " blocked for I/O." << std::endl;
//                //waitingQueue.push_back(process);
//                CPU_TAKT++;
//                break;
//            case 'X': {
//                    Process *newProcess = new Process();
//                    newProcess = loadProcessAndCreateNewProcess(instruction.substr(2));
//                    //check if id = -1 bevor to add this Process to the ReadyQueue
//                    //because here there is no new Process just don't add it
//                    if(newProcess->id != -1){
//                        readyQueue.push_back(process);
//                        readyQueue.push_back(newProcess);
//                    }

//                    CPU_TAKT++;
//                    break;
//                }
//            case 'Z':
//                //std::cout << "Process " << process->programName << " terminated." << std::endl;
//                process->status = TERMINATED;
//                CPU_TAKT++;
//                break;
//            default:
//                std::cout << "Invalid instruction: " << instruction << std::endl;
//                CPU_TAKT++;
//        }

//    }


//}










//#include <iostream>
//#include <algorithm>
//using namespace std;

//int main()
//{
//    bool RheiheA=true,RheiheB=true;
//    int zahl=0;
//    int i=1,j=1;
//    int Eingabe[100];
//    int EingabeCounter = 0;
//    int Mine[3] = {55,11,22};
//    bool SpielEnde= true;

//    while(SpielEnde){
//        cout<<endl;
//       while(i<=100){
//            if(RheiheA){cout<<"a)             ";RheiheA=false;}
//            if(RheiheB){cout<<"b)"<<endl;RheiheB=false;}

//            while(j<=10){
//                if(any_of(begin(Eingabe),end(Eingabe),[=](int n){return n==i;})){
//                    cout << "X";
//                }else{
//                    cout << "*";
//                }
//                j++;
//                i++;
//            }

//            j=1;

//            cout<<"     ";

//            while(j<=10){
//                if(any_of(begin(Eingabe),end(Eingabe),[=](int n){return n==i;})){
//                    cout << "X";
//                }else{
//                    cout << "*";
//                }
//                j++;
//                i++;
//            }
//            j=1;
//            cout<<endl;

//       }

//         i=1;
//         while(true){
//            cout<<"Gib Zahl Ein Zwischen 1 und 100"<<endl;
//            cin>>zahl;

//            if(any_of(begin(Eingabe),end(Eingabe),[=](int n){return n == zahl; }))
//                cout<<"Diese Zahl wurde schon eingegeben"<<endl;

//             else if((zahl<=100 && zahl>=1)){
//                if(any_of(begin(Mine),end(Mine),[=](int n){return n == zahl; }))
//                    SpielEnde = false;
//                Eingabe[EingabeCounter]=zahl;
//                EingabeCounter++;
//                zahl=0;
//                break;
//             }

//        }


//    }

//    cout<<"Du hast leider Verloren aber schon "<<EingabeCounter <<" Schritte gemacht"<<endl;





//    i=1;
//    while(i<=100){
//            if(RheiheA){cout<<"a)             ";RheiheA=false;}
//            if(RheiheB){cout<<"b)"<<endl;RheiheB=false;}

//            while(j<=10){
//                 if(any_of(begin(Mine),end(Mine),[=](int n){return n==i;})){
//                   cout << "O";
//                }
//                else if(any_of(begin(Eingabe),end(Eingabe),[=](int n){return n==i;})){
//                    cout << "X";

//                }else{
//                    cout << "*";
//                }
//                j++;
//                i++;
//            }

//            j=1;

//            cout<<"     ";

//            while(j<=10){
//                if(any_of(begin(Mine),end(Mine),[=](int n){return n==i;})){
//                   cout << "O";
//                }
//                else if(any_of(begin(Eingabe),end(Eingabe),[=](int n){return n==i;})){
//                    cout << "X";

//                }else{
//                    cout << "*";
//                }
//                j++;
//                i++;
//            }
//            j=1;
//            cout<<endl;

//       }


//    return 0;
//}
