#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void jWait() {
	int x;
	for (x = 0; x < 2; x++) {
		Sleep(100);
		cout << "" << "\n";
		Sleep(100);
	}
}


int main()
{
	string curDir = "";//current direction
	string start = ""; // user decision to start the game

	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hC, 11);

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
	
	do { 
		cout << "Would you like to begin your adventure?(yes or no)" << "\n";
		cin >> start;
		for (int i = 0; i < start.length(); ++i) {
			start[i] = tolower(start[i]);
		}

	} while (start != "yes" && start != "no");
	
	if (start == "no") {
		return(0);
	} 
		
	
}//end of main
