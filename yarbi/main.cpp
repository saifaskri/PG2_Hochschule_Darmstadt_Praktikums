#include <iostream>
#include <deque>
#include <vector>
#include <fstream>
#include <iomanip>

//lösche das einfach
#define PROCESS_PATH_TEST "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\yarbi\\process\\meinprogramm\\"

#define PROCESS_PATH "C:\\Users\\saifa\\Desktop\\Hochschule\\PG2_Hochschule_Darmstadt_Praktikums\\yarbi\\process\\"

const int QUNTUM = 7 ;

#define SPACE_BETWEEN_WORDS 15
#define SEPARATOR ' '

#define READY 1
#define WAITING 0


using namespace std;

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
    int NumberOfCycle;

};




struct ProcessVerlauf {

    string nameProcess;
    int id;
    int ACCOutputValue;
    int StartTakt;
    int EndTakt;
    int VerwileZeit;

};


struct Processmanagment {

   vector<ProcessVerlauf*> processDetails;

   ProcessVerlauf* getProcessDetailsToUpdate(int id){
       for (int i = 0; i < processDetails.size(); ++i) {
           if(processDetails[i]->id == id){
                  return processDetails[i];
           }
       }
       return nullptr;
   }

};



class IOUnit{
public:
    deque <Process*> waitingQueue;
};

class CPU{
public:

    int ACC;
    int PC;
    int CPU_TAKT = 0;
    int ProcessIdCounter = 0 ;
    IOUnit io_unit;
    deque <Process*> readyQueue;
    Processmanagment pm;

    bool primetiveScheduling = false;

    CPU(){
        Process *initProcess = new Process();
        initProcess = new Process();
        loadProgrammInProcess("init",initProcess);
        readyQueue.push_back(initProcess);
    };

    void getQueues(){
        string draw = "===================================================================================================================";
        cout<<endl;cout<<endl;
        cout<<draw<<endl;

        cout<<CPU_TAKT<<endl;

        cout<<endl;cout<<endl;

        cout<<"ready Qeueu"<<"  ";
        for (const auto& rq : readyQueue) {
                cout << rq->programName << " "<<rq->id<<" | ";
        }

        cout<<endl;cout<<endl;

        cout<<"Waiting Qeueu"<<"  ";
        if(!io_unit.waitingQueue.empty()){
            for (const auto& wq : io_unit.waitingQueue) {
                    cout <<"=> RTakt:"<< wq->RemainedWaitingTakt<<" "<<wq->programName << ":"<<wq->id<<" NextIntr.=> "
                      <<wq->instructions[wq->programCounter]<<"  | "<<endl<<"               ";
            }
        }

        cout<<endl;cout<<endl;

        cout<<draw<<endl;

        cout<<endl;cout<<endl;

    }

    void saveStateOfCPUInProcess(Process *p){
        p->accumulator = ACC;
        p->programCounter = PC;
    };

    void PrintZusammenfassung_header(){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "PID";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Prozess";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Start";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Ende";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Verweilzeit";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "Akkumulator"<<endl;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "--";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-------";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-----";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "----";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-----------";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-----------"<<endl;
    };

    void PrintZusammenfassung(){
        for (int i = 0; i < pm.processDetails.size(); ++i) {
            pm.processDetails[i]->VerwileZeit = pm.processDetails[i]->EndTakt - pm.processDetails[i]->StartTakt;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->id;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->nameProcess;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->StartTakt;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->EndTakt;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->VerwileZeit;
            cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << pm.processDetails[i]->ACCOutputValue<<endl;
        }

    };

    void Buchhaltung_no_Process(){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << CPU_TAKT;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "---";
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << PC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << ACC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << io_unit.waitingQueue.front()->RemainedWaitingTakt ;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) <<io_unit.waitingQueue.front()->id;
       cout<<endl<<endl;
    };

    void Buchhaltung(Process *process){
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << CPU_TAKT;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->id;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->programName;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << PC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << ACC;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << "-" ;
       cout << left << setw(SPACE_BETWEEN_WORDS) << setfill(SEPARATOR) << process->instructions[PC] ;
       cout<<endl<<endl;
    };

    void loadProgrammInProcess(const string& programName , Process *process) {

        //start read Programm
            ifstream programFile(PROCESS_PATH + programName);
            if (!programFile.is_open()){
                cout << "Failed to Load Process " << programName <<endl;
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
            process->NumberOfCycle = 0;
            process->id = ProcessIdCounter;
            process->status = READY;
        //end set Default Values for a new Process

        //start set Default Values for a new ProcessVerlauf
            ProcessVerlauf *p = new ProcessVerlauf();
            p->StartTakt = CPU_TAKT;
            p->nameProcess = process->programName;
            p->id = process->id;
            p->ACCOutputValue = process->accumulator ;
            pm.processDetails.push_back(p);
            p->EndTakt = 0;
            p->VerwileZeit = 0  ;
        //end set Default Values for a new ProcessVerlauf

        //static counter
        ProcessIdCounter++;

    }

    void executeProgram(Process *process) {

        //CPU Program Counter eqauls programCounter of the Process
        PC = process->programCounter;
        //CPU accumulator eqauls accumulator of the Process
        ACC = process->accumulator;


        while (PC < process->instructions.size()) {

            const string& instruction = process->instructions[PC];
            char command = instruction[0];



            Buchhaltung(process);
            CPU_TAKT++;
            PC++;


            switch (command) {
                case 'L':

                    ACC = stoi(instruction.substr(2));

                    //Check Waiting Process
                    if(! io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
                            saveStateOfCPUInProcess(process);
                            readyQueue.push_back(process);
                            return;
                        }
                    }

                    break;
                case 'A':
                    ACC += stoi(instruction.substr(2));

                    //Check Waiting Process
                    if(!  io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
                            saveStateOfCPUInProcess(process);
                            readyQueue.push_back(process);
                            return;
                        }
                    }

                    break;
                case 'S':
                    ACC -= stoi(instruction.substr(2));

                    //Check Waiting Process
                    if(!  io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
                            saveStateOfCPUInProcess(process);
                            readyQueue.push_back(process);
                            return;
                        }
                    }

                    break;
                case 'P':{
                    //Simulate I/O operation (blocking)
                    //cout << "Process " << process->programName << " blocked for I/O." << std::endl;

                    //Check Waiting Process
                    if(!  io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
                        }
                    }

                    Process *processToAddInWaitingQueue = new Process();

                    saveStateOfCPUInProcess(process);
                    process->status = WAITING;
                    process->RemainedWaitingTakt = 4;

                    //processToAddInWaitingQueue = process;
                    //io_unit.waitingQueue.push_back(processToAddInWaitingQueue);

                    io_unit.waitingQueue.push_back(process);



                    return;
                }
                case 'X': {

                    saveStateOfCPUInProcess(process);
                    //CurrentProcess beleibt in seinem Platz
                    readyQueue.push_back(process);

                    Process *newProcess = new Process();
                    loadProgrammInProcess(instruction.substr(2),newProcess);
                    readyQueue.push_back(newProcess);

                    //Check Waiting Process
                    if(!  io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
                            //saveStateOfCPUInProcess(process);
                            //readyQueue.push_back(process);
                            //return;
                        }
                    }

                    return;

                    }
                case 'Z':
                    //Check Waiting Process
                    pm.getProcessDetailsToUpdate(process->id)->EndTakt =CPU_TAKT;
                    pm.getProcessDetailsToUpdate(process->id)->ACCOutputValue = ACC;

                    if(!  io_unit.waitingQueue.empty()){
                        io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                        if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                            io_unit.waitingQueue.front()->status = READY ;
//                            saveStateOfCPUInProcess(process);
//                            readyQueue.push_back(process);
                            //return;
                        }
                    }
                    //std::cout << "Process " << process->programName << " terminated."" "<<process->id  << std::endl<<endl;
                    delete process;
                    return;
                default:
                    std::cout << "Invalid instruction: " << instruction << std::endl;
                    break;
            }//end switch

            if(primetiveScheduling){
                if( process->NumberOfCycle >  5 ){
                    //zu waitingsQueue hinzufügen
                    saveStateOfCPUInProcess(process);
                    process->NumberOfCycle  = 0 ;
                    process->status = WAITING;
                    process->RemainedWaitingTakt= 4;
                    io_unit.waitingQueue.push_back(process);
                    return;
                }else{
                    process->NumberOfCycle++;
                }
            }

        }//end While
    };

    void schedule() {


        while (!readyQueue.empty() || !io_unit.waitingQueue.empty()) {

           ///*== nur Für Testen ================>*/ getQueues();// <======kommentiere einfach aus =============

            if(!io_unit.waitingQueue.empty()){
                if(io_unit.waitingQueue.front()->status == READY){

                    Process *processToAddInReadyQueue = new Process();
                    processToAddInReadyQueue = io_unit.waitingQueue.front();
                    readyQueue.push_back(processToAddInReadyQueue);
                    io_unit.waitingQueue.pop_front();
                }
            }

            if(readyQueue.empty() && !io_unit.waitingQueue.empty()){
                CPU_TAKT++;
                Buchhaltung_no_Process();
                io_unit.waitingQueue.front()->RemainedWaitingTakt--;
                if(io_unit.waitingQueue.front()->RemainedWaitingTakt == 0 ){
                    io_unit.waitingQueue.front()->status = READY ;
                }
            }

            if(!readyQueue.empty()){
                Process *processToExecute = new Process();
                processToExecute = readyQueue.back();
                readyQueue.pop_back();
                executeProgram(processToExecute);

            }



        }// end while
        //std::cout << "Executing process: " << processToExecute->programName<<" "<<processToExecute->id << std::endl<<endl;

    }
};


int main()
{
    Buchhaltung_UpBar();
    CPU cpu = CPU();

    cpu.primetiveScheduling = true;

    cpu.schedule();
    cpu.PrintZusammenfassung_header();
    cpu.PrintZusammenfassung();

    return 0;
}

