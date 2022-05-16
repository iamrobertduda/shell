#include <iostream>
#include <string>

using namespace std;

void openShell() {
    cout << "Erwarte Eingabe" << endl;
    string input;
    while(cin >> input) {
        if(input == "logout") {
            cout << "Sicher, dass du das Programm verlassen moechtest? (Y/n)" << endl;
            string logout;
            cin >> logout;
            if(logout == "Y") {
                exit(0);
            }
            continue;
        }
        //Befehl ausführen
    }

}

int main() {
    openShell();
    return 0;
}