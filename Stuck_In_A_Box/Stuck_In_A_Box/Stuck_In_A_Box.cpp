﻿#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

void jWait() {
    int x;
    for (x=0 ; x < 2; x++) {
            sleep(1);
            cout << "" << "\n";
            sleep(1);
            }
        }


int main()
{
string curDir = "";//current direction
string start = ""; // user decision to start the game

jWait();
cout << " _____ _              _        _____          ___    ______           " << endl;
cout << "/  ___| |            | |      |_   _|        / _ \\   | ___ \\          " << endl;
cout << "\\ `--.| |_ _   _  ___| | __     | | _ __    / /_\\ \\  | |_/ / _____  __" << endl;
cout << " `--. \\ __| | | |/ __| |/ /     | || '_ \\   |  _  |  | ___ \\/ _ \\ \\/ /" << endl;
cout << "/\\__/ / |_| |_| | (__|   <     _| || | | |  | | | |  | |_/ / (_) >  < " << endl;
cout << "\\____/ \\__|\\__,_|\\___|_|\\_\\    \\___/_| |_|  \\_| |_/  \\____/ \\___/_/\\_\\" << endl;
jWait();
cout << "written By Liam, Calvin, and Jacob" << "\n";
jWait();
cout << "Would you like to begin your adventure?(yes or no)" << "\n";
cin >> start;

for(int i = 0; i < start.length(); ++i) {
    start[i] = tolower(start[i]);
}
/*
while (true):
    if{start == "yes":
    cout << "Perfect! Lets get started... Do you remember your name?";
    break;
    }
    if start == "no":
    exit(0);
    break;
    cout << "That is an invalid choice, Please try again" << "\n";

    */

}//end of main
