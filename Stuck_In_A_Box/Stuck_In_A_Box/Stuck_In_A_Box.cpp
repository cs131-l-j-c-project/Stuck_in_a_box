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
	string curDir = "neutral";//current direction
	string start; // user decision to start the game
	int roomNo = 0;
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
		//Put Room/Wall Descriptions here(Do we want to have a stutter on that text as well?)
		if (roomNo = 0) {
			if (curDir == "north") {
				cout << "There is a keypad on the wall with a 4- digit number to type in.";
			}
			else if (curDir == "east") {
				cout << "There is a panel with 3 flathead screws holding it in. If i had a screwdriver, i can probably get it off…";
			}
			else if (curDir == "south") {
				cout << "There is a steel wall here. Nothing else of interest.";
			}
			else if (curDir == "west") {
				cout << "There is a phone here, with a number pad to call someone. Does it still work…?";
			}
			else if (curDir == "up") {
				cout << "There is a rusted metal trapdoor. It is locked with a padlock, and it does not budge otherwise. Maybe I could find a key around here…";
			}
			else if (curDir == "down") {
				cout << "The ground is dusty and smells like rust and ammonia, not the best place to wake up to. There is a single note of paper on the ground with some numbers on it.";
			}
			else if (curDir == "neutral") {
				cout << "You wake up in a room";
			}
			cout << endl << endl;
		}

		action = parseInput();
		if (action[0] == "exit")
			break;
		
		//Sort out what the user wanted
		if (action[0] == "look") {
			if (action[1] == "west" || action[1] == "east" || action[1] == "south" || action[1] == "north" || action[1] == "up" || action[1] == "down") {
				curDir = action[1];
			}
			else if (action[1] == "left") {
				if (curDir == "north")
					curDir = "west";
				else if (curDir == "east")
					curDir = "north";
				else if (curDir == "south")
					curDir = "east";
				else if (curDir == "west")
					curDir = "south";
			}
			else if (action[1] == "right") {
				if (curDir == "north")
					curDir = "east";
				else if (curDir == "east")
					curDir = "south";
				else if (curDir == "south")
					curDir = "west";
				else if (curDir == "west")
					curDir = "north";
			}
		}
		else if (action[0] == "grab" || action[0] == "take") {
			//Item aquisition goes here
		}
		else if (action[0] == "use") {
			//Item usage goes here. May need some specific additional commands for those who say "Cut wire" instead of "Use Scissors on wire"
		}
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
	cin >> ws; //Deals with cin and getline conflicts
	getline(cin, s);
	lowerStr(s); //decreases variation of possible input(Easier comparisons)
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


