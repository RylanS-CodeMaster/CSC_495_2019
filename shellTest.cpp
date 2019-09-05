#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

using namespace std;

int main(int argc, char *argv[])
{

        string command;
        char pwd[100];

        cout << "This is a simple Shell, type (exit) to exit\n";
        cout << "You may use (help) to display more information\n";

        while (command != "exit")
        {
                cout << getcwd(pwd, 100) << " >> ";
                cin >> command;

                if(command == "ls")
                {
                        pid_t pid = fork();
                        if(pid < 0)
                        {
                                perror("Fork Failed");
                                exit(1);
                        }
                        else if(pid == 0)
                        {
                                char * ls_args[] = { "/bin/ls", "-l", NULL};
                                execv( ls_args[0], ls_args);
                        }
			
                }
                else if(command == "cd")
                {
                        char directoryChange[100];
                        cin >> directoryChange;

                        if(chdir(directoryChange) == -1)
                        {
                                cout << "Directory does not exist!" << endl;
                        }
                }
                else if(command == "help")
                {
                }
                else
                {
                        cout << "Not a command implmented in this basic shell" << endl;
                        cout << "If you need help type (help)" << endl;
                }
        }
        return 0;
}
