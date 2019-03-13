#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;

void lowerStr(string &s);
void printTitle();
vector<string> parseInput();

int main()
{
	string curDir;//current direction
	string start; // user decision to start the game
	vector<string> action;//Vector of words to do an action
	COORD afterTitle;
	afterTitle.X = 0;
	afterTitle.Y = 9;

	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hC, 11);

	printTitle();

	do {
		cout << "Would you like to begin your adventure?(yes or no)" << "\n";
		cin >> start;
		lowerStr(start);

	} while (start != "yes" && start != "no");

	if (start == "no") {
		return(0);
	}

	SetConsoleCursorPosition(hC, afterTitle);
	cout << "                                                  " << endl
		<< "   " << endl;
	SetConsoleCursorPosition(hC, afterTitle);

	while (true) {
		//Put Descriptions here(Do we want to have a stutter on that text as well?)
		action = parseInput();
		if (action[0] == "exit")
			break;
		//Sort out what the user wanted
	}
	
	system("pause");
}

void lowerStr(string &s) {
	for (int i = 0; i < s.length(); ++i) {
		s[i] = tolower(s[i]);
	}
}

void printTitle() {
	ifstream fin;
	char c;
	int i = 0;
	fin.open("Title.txt"); // This file is needed in the containing folder
	while (fin.get(c)) {
		if (i % 3)
			Sleep(2);
		cout << c;
		i++;
	}
	fin.close();
	cout << endl << endl;
	cout << "written By Liam, Calvin, and Jacob" << endl << endl;
}

vector<string> parseInput() {
	string s;
	vector<string> vect = {""};
	int word = 0;
	cout << "What would you like to do?" << endl;
	cin >> ws;
	getline(cin, s);
	lowerStr(s);
	for (int i = 0; i < s.length(); i++) {
		if (isspace(s[i])) {
			word++;
		}
		else {
			vect.resize(word + 1); //Makes sure vect holds only as many words as exist in the given string
			vect[word] += s[i];//Appends the char in s[i] into vect's current index
		}
	}
	return vect;
}

