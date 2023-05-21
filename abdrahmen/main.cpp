#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <iomanip>

#define PROCESS_PATH "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\p3BS\\process\\"

#define SPACE_BETWEEN_WORDS 15
#define SEPARATOR ' '


#define READY 1
#define WAITING 0



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

    int id ;
    string programName;
    vector<string> instructions;
    int accumulator;
    int programCounter;

    int RemainedWaitingTakt;

    int status;

};


struct IOUnit{

    deque <Process*> waitingQueue;

    int WaitingsCPU_TAKTs = 4 ;

void handelProcessesInWaitingMode(){

    if(!waitingQueue.empty()){
        WaitingsCPU_TAKTs--;
        //cout<< waitingQueue.front()->programName<<" "<< waitingQueue.front()->id<<" lena -- 3amlat"<<endl;
        if(WaitingsCPU_TAKTs == 0){
            //cout<< waitingQueue.front()->programName<<" ready geworden"<<endl;

            // set The Process ready
            waitingQueue.front()->status = READY;
            //set that for the next Process
            WaitingsCPU_TAKTs = 4;
        }
    }


};

    IOUnit(){};
};



struct CPU{

    int ACC;
    int PC;
    string IR;
    int CPU_TAKT = 0;
    //Process  *executed_Process;

    IOUnit io_unit;
    deque <Process*> readyQueue;

    void getQueues(){
        string draw = "===================================================================================================================";
        cout<<endl;cout<<endl;
        cout<<draw<<endl;

        cout<<CPU_TAKT<<endl;

        cout<<endl;cout<<endl;

        cout<<"ready Qeueu"<<"  ";
        if(readyQueue.empty())
            cout<<"leer ";
            for (const auto& rq : readyQueue) {
                    cout << rq->programName << " "<<rq->id<<" | ";
            }



        cout<<endl;cout<<endl;


        cout<<"Waiting Qeueu"<<"  ";
        if(!io_unit.waitingQueue.empty()){
            for (const auto& wq : io_unit.waitingQueue) {
                    cout <<"=> RTakt "<< wq->RemainedWaitingTakt<<" "<<wq->programName << " id: "<<wq->id<<" NextIntr. => "
                      <<wq->instructions[wq->programCounter]<<"  | "<<endl<<"               ";
            }
        }

        cout<<endl;cout<<endl;

        cout<<draw<<endl;

        cout<<endl;cout<<endl;

    }


    void testIfWaitingsProcessIsReadyThanSwitchToIt(Process *currentProcess){

        if(!io_unit.waitingQueue.empty()){

            if(io_unit.waitingQueue.front()->status == READY){

                //if duiring the execute process is becomme ready
                if(currentProcess != nullptr){

                    Process *n  =  new Process();

                    saveStateOfCPUInProcess(currentProcess);
                    n = currentProcess;
                    //Process beleibt in seinem Platz
                    readyQueue.push_back(n);

                }
                Process *nn  =  new Process();
                nn =  io_unit.waitingQueue.front();
                readyQueue.push_back(nn);
                io_unit.waitingQueue.pop_front();
                return;
            }

        }

    }

    void saveStateOfCPUInProcess(Process *p){
        p->accumulator = ACC;
        p->programCounter = PC;
    };

    void loadProcessAndCreateNewProcess(const std::string& programName , Process *process) {


        //start read Programm
            ifstream programFile(PROCESS_PATH + programName);
            if (!programFile.is_open()){
                cout << "Failed to Load Process " << programName <<endl;
                //check if id = -1 bevor to add this Process to the ReadyQueue
                //because here there is no new Process just don't add it
                return ;
            }
            string instruction;
            while (getline(programFile, instruction)) {
                process->instructions.push_back(instruction);
            }
            programFile.close();
        //end read Programm

        //start set Default Values for a new Process
            process->programName = programName;
            process->accumulator = 0;
            process->programCounter = 0;
            process->id = IDcounter;
            process->status = READY;
        //end set Default Values for a new Process


        //static counter
        IDcounter++;

    }

    void Buchhaltung(Process *process){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << CPU_TAKT;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->id;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->programName;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << PC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << ACC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << 7 ;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->instructions[PC] ;
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

    CPU() {
        Process *initProcess = new Process();
        initProcess = new Process();
        loadProcessAndCreateNewProcess("init",initProcess);
        readyQueue.push_back(initProcess);
    }

    void executeProgram(Process *process) {

        //CPU Program Counter eqauls programCounter of the Process
        PC = process->programCounter;
        //CPU accumulator eqauls accumulator of the Process
        ACC = process->accumulator;

        while (PC < process->instructions.size()) {
            const string& instruction = process->instructions[PC];
            char command = instruction[0];

            getQueues();            
            Buchhaltung(process);

            CPU_TAKT++;
            //CHECk waintingsQueue
            io_unit.handelProcessesInWaitingMode();
            testIfWaitingsProcessIsReadyThanSwitchToIt(process);

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

                    //SaveState
                    saveStateOfCPUInProcess(process);
                    process->status = WAITING;

                    io_unit.waitingQueue.push_back(process);

                    return;
                case 'X': {
                            //SaveState
                            saveStateOfCPUInProcess(process);
                            //create newProcess and Load Programm
                            Process *newProcess = new Process();
                            loadProcessAndCreateNewProcess(instruction.substr(2),newProcess);
                            //this line we don't need
                            process->status = READY;
                            //Process beleibt in seinem Platz
                            readyQueue.push_back(process);
                            // Add new At the end
                            readyQueue.push_back(newProcess);
                            return;
                    }
                case 'Z':
                        //std::cout << "Process " << process->programName << " terminated."" "<<process->id  << std::endl<<endl;
                        delete process;
                        return;
                default:
                    std::cout << "Invalid instruction: " << instruction << std::endl;
                    break;
            }//end switch



        }//end while
    }

    void schedule() {

        while (!readyQueue.empty() || !io_unit.waitingQueue.empty()) {


                if(!io_unit.waitingQueue.empty()){
                    if(io_unit.waitingQueue.front()->status == READY){
                        Process *processToAddInReadyQueue = new Process();
                        processToAddInReadyQueue = io_unit.waitingQueue.front();
                        readyQueue.push_back(processToAddInReadyQueue);
                        io_unit.waitingQueue.pop_front();
                    }
                }

                //execute ready process
                if(!readyQueue.empty()){
                    Process *processToExecute = new Process();
                    processToExecute = readyQueue.back();
                    readyQueue.pop_back();
                    //std::cout << "Executing process: " << processToExecute->programName<<" "<<processToExecute->id << std::endl<<endl;
                    executeProgram(processToExecute);
                }else{
                    //CHECk waintingsQueue
                    Buchhaltung_no_Process();
                    CPU_TAKT++;
                    //CHECk waintingsQueue
                    io_unit.handelProcessesInWaitingMode();
                    testIfWaitingsProcessIsReadyThanSwitchToIt(nullptr);
                }

        }//end while

    }


};



int main()
{
    Buchhaltung_UpBar();

    CPU cpu = CPU();

    cpu.schedule();

    exit(0);  // Exit the program

    return 0;


}
