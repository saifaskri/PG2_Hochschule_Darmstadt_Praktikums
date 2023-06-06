
//# OOP Recap Exercise

//## Description
//This is an easy exercise for an OOP Recap. You shouldn't have many problems to resolve that exercise. You have to create an easy calculation tool for geometric surfaces.
//- Rectangle
//- Triangle
//- Circle

//## Task
//Let all the classes inherit from a superclass called **GeometricSurface**, so that you can write the following in a main function:

//```c++
//double radius = 2.3;
//GeometricSurface* circle = new Circle(radius);

//double a = 2.3;
//double b = 3.2;
//double c = 5.1;
//GeometricSurface* triangle = new Triangle(a, b, c);

//double a = 2.3;
//double b = 3.2;
//GeometricSurface* rectangle = new Rectangle(a, b);

//circle->calculateArea();
//circle->calculatePerimeter();

//triangle->calculateArea();
//triangle->calculatePerimeter();

//rectangle->calculateArea();
//rectangle->calculatePerimeter();
//```

//Decide where to put there calculation logic and where to put the attributes.




#include <iostream>

using namespace std;


class GeometricSurface{
private:
    double area;
    double periMeter;
public :
   GeometricSurface();
   virtual void calculateArea()= 0;
   virtual void calculatePerimeter()=0;
};



class Circle: public GeometricSurface{
private:
    double radius;
public :
    Circle();
    Circle(double radius):radius(radius){};
    void calculateArea();
    void calculatePerimeter();
};


int main() {

    double radius = 2.3;
    GeometricSurface* circle = new Circle(radius);
    return 0;
}

























































////#include <iostream>
////#include <cstring>
////#include <cstdlib>
////#include <unistd.h>
////#include <sys/wait.h>

////using namespace std;

////void printPrompt() {
////    char cwd[1024];
////    getcwd(cwd, sizeof(cwd));
////    cout << cwd << " > ";
////}

////void executeCommand(char* tokens[], int num_tokens, bool background) {
////    pid_t pid = fork();

////    if (pid == -1) {
////        cerr << "Fork failed" << endl;
////        exit(EXIT_FAILURE);
////    } else if (pid == 0) {
////        // Child process
////        if (execvp(tokens[0], tokens) == -1) {
////            cerr << "Error executing command" << endl;
////            exit(EXIT_FAILURE);
////        }
////    } else {
////        // Parent process
////        if (!background) {
////            // Wait for child process to finish
////            int status;
////            waitpid(pid, &status, 0);
////        } else {
////            // Print child process ID and continue
////            cout << "Child process ID: " << pid << endl;
////        }
////    }
////}

////int main() {
////    string input;
////    const char* delimiters = " \t\n\r\f\v";
////    const char* bg_delimiters = "&";

////    while (true) {
////        printPrompt();

////        // Get user input
////        getline(cin, input);

////        // Check for exit command
////        if (input == "exit") {
////            // Confirm exit with user
////            char confirm;
////            cout << "Are you sure you want to exit? (y/n) ";
////            cin >> confirm;
////            if (confirm == 'y' || confirm == 'Y') {
////                break;
////            } else {
////                cin.ignore();
////                continue;
////            }
////        }

////        // Check for empty input
////        if (input.empty()) {
////            continue;
////        }

////        // Tokenize input string
////        char* tokens[1024];
////        char* token = strtok(const_cast<char*>(input.c_str()), delimiters);
////        int num_tokens = 0;
////        bool background = false;

////        while (token != NULL) {
////            if (strcmp(token, bg_delimiters) == 0) {
////                // Background command requested
////                background = true;
////                break;
////            }
////            tokens[num_tokens++] = token;
////            token = strtok(NULL, delimiters);
////        }

////        // Execute command
////        tokens[num_tokens] = NULL;
////        executeCommand(tokens, num_tokens, background);
////    }

////    return 0;
////}













////#include <iostream>
////#include <string>
////#include <cstring>
////#include <unistd.h>
////#include <sys/wait.h>
////#include <signal.h>
////#include <vector>

////using namespace std;

////void handle_signal(int signum)
////{
////    cout << "Received signal: " << signum << endl;
////}

////int main()
////{
////    char cwd[1024];
////    char* tokens[100];
////    int num_tokens = 0;
////    string command;

////    while (true) {
////        if (getcwd(cwd, sizeof(cwd)) != NULL)
////            cout << cwd << " > ";
////        else
////            cout << "Error: Could not get current directory" << endl;

////        getline(cin, command);

////        // Ignore empty commands
////        if (command.empty()) {
////            continue;
////        }

////        // Check if the command should run in the background
////        bool run_in_background = false;
////        if (command.back() == '&') {
////            run_in_background = true;
////            command.pop_back();
////        }

////        // Parse command into tokens
////        char* token = strtok(const_cast<char*>(command.c_str()), " ");
////        num_tokens = 0;
////        while (token != NULL) {
////            tokens[num_tokens] = token;
////            num_tokens++;
////            token = strtok(NULL, " ");
////        }
////        tokens[num_tokens] = NULL;

////        // Exit command
////        if (strcmp(tokens[0], "exit") == 0) {
////            cout << "Are you sure you want to exit? (y/n)" << endl;
////            string response;
////            getline(cin, response);
////            if (response == "y") {
////                break;
////            }
////            else {
////                continue;
////            }
////        }

////        // Fork and execute command
////        pid_t pid = fork();
////        if (pid < 0) {
////            cout << "Error: Fork failed" << endl;
////            continue;
////        }
////        else if (pid == 0) {
////            // Child process
////            if (execvp(tokens[0], tokens) < 0) {
////                cout << "Error: Command not found" << endl;
////                exit(1);
////            }
////        }
////        else {
////            // Parent process
////            if (!run_in_background) {
////                // Wait for child process to finish
////                int status;
////                waitpid(pid, &status, 0);
////                if (WIFEXITED(status)) {
////                    cout << "Process " << pid << " exited with status " << WEXITSTATUS(status) << endl;
////                }
////            }
////            else {
////                // Run in background and print process ID
////                cout << "Process " << pid << " is running in the background" << endl;
////                signal(SIGCHLD, handle_signal);
////            }
////        }
////    }

////    return 0;
////}






////#include <sys/wait.h>
////#include <unistd.h>
////#include <iostream>

////int main() {
////    pid_t pid = fork();
////    if (pid == 0) {
////        // child process
////        char* args[] = {"ls", "-l", nullptr}; // command to run
////        execvp(args[0], args); // run command
////        std::cerr << "Failed to execute command." << std::endl;
////        return 1;
////    } else if (pid > 0) {
////        // parent process
////        std::cout << "Parent process waiting for child..." << std::endl;
////        int status;
////        waitpid(pid, &status, 0); // wait for child process to complete
////        if (WIFEXITED(status)) {
////            std::cout << "Child process exited with status " << WEXITSTATUS(status) << std::endl;
////        } else {
////            std::cout << "Child process terminated abnormally." << std::endl;
////        }
////    } else {
////        // error
////        std::cerr << "Failed to fork process." << std::endl;
////        return 1;
////    }
////    return 0;
////}






//#include <iostream>
//#include <sstream>
//#include <string>
//#include <cstring>
//#include <unistd.h>
//#include <sys/wait.h>

//int main() {
//    while (true) {
//        std::cout << "MyShell> ";
//        std::string line;
//        std::getline(std::cin, line);

//        if (line.empty()) {
//            continue;
//        }

//        // Parse the input line
//        std::istringstream iss(line);
//        std::string command;
//        std::string last_char;
//        iss >> command >> std::noskipws >> last_char;

//        // Check if the command should be executed in the background
//        bool is_background = !last_char.empty() && last_char.back() == '&';

//        // Remove the '&' character from the command if necessary
//        if (is_background) {
//            command.erase(command.size() - 1);
//        }

//        // Fork a child process to execute the command
//        pid_t pid = fork();
//        if (pid == 0) {
//            // Child process
//            // Convert the command string to a C-style null-terminated string
//            char* args[2] = {const_cast<char*>(command.c_str()), nullptr};
//            int ret = execvp(args[0], args);
//            if (ret == -1) {
//                std::cerr << "Error executing command: " << std::strerror(errno) << std::endl;
//            }
//            return ret;
//        } else if (pid > 0) {
//            // Parent process
//            if (is_background) {
//                std::cout << "Background process started with PID " << pid << std::endl;
//            } else {
//                int status;
//                waitpid(pid, &status, 0);
//                if (WIFEXITED(status)) {
//                    std::cout << "Command exited with status " << WEXITSTATUS(status) << std::endl;
//                } else if (WIFSIGNALED(status)) {
//                    std::cout << "Command terminated by signal " << WTERMSIG(status) << std::endl;
//                }
//            }
//            // Check for any child processes that have exited but not yet been waited for
//            pid_t child_pid;
//            int child_status;
//            while ((child_pid = waitpid(-1, &child_status, WNOHANG)) > 0) {
//                if (WIFEXITED(child_status)) {
//                    std::cout << "Child process " << child_pid << " exited with status " << WEXITSTATUS(child_status) << std::endl;
//                } else if (WIFSIGNALED(child_status)) {
//                    std::cout << "Child process " << child_pid << " terminated by signal " << WTERMSIG(child_status) << std::endl;
//                }
//            }
//        } else {
//            // Error forking
//            std::cerr << "Error forking process: " << std::strerror(errno) << std::endl;
//        }
//    }

//    return 0;
//}












