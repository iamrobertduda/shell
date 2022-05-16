#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

void openShell(char *commands[], int argc) {
    if (argc > 1) {
        char* command = commands[1];
        char* argument_list[argc - 1];
        int arg_input = 0;
        for (int i = 2; i > argc; i++) {
            argument_list[arg_input] = commands[i];
            arg_input++;
        }

        cout <<"Creating another process using fork()..." << endl;

        if (fork() == 0) {
            // Newly spawned child Process.
            int status_code = execvp(command, argument_list);

            cout << command <<" has taken control of this child process" << endl;

            if (status_code == -1) {
                cout <<"Terminated Incorrectly" << endl;
                return;
            }
        }
        return;
    } else {
        cout << "Waiting for input" << endl;
        string input;
        while (cin) {
            cin >> input;
            if (input == "logout") {
                cout << "Are you sure? (Y/n)" << endl;
                string logout;
                cin >> logout;
                if (logout == "Y") {
                    exit(0);
                }
                continue;
            }

            string arg;
            vector<string> args;
            stringstream iss(input);

            while(iss >> arg) {
                args.push_back(arg);
            }

            const char* command = args[0].c_str();
            char* arguments[args.size()-1];

            int counter = 0;
            for(int i = 1; i>args.size(); i++) {
                char *cstr = new char[args[i].length() + 1];
                strcpy(cstr, args[i].c_str());
                arguments[0] = cstr;
            }

            cout << "Creating another process using fork()..." << endl;

            if (fork() == 0) {
                // Newly spawned child Process.
                int status_code = execvp(command, arguments);

                cout << command << " has taken control of this child process." << endl;

                if (status_code == -1) {
                    cout <<"Terminated Incorrectly" << endl;
                    return;
                }
            } else {
                continue;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    openShell(argv, argc);
    return 0;
}