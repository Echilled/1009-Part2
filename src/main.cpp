#include "Game_Manager.h"
#include <string>
#include <iostream>
int main() {
	int PH;
	int players = 5;
	cout << "Number of Bot(AI): ";

	try {
		while (!(cin >> players)) {
			continue;
		}
	}
	catch (...) {
		cout << "bad\n";
	}

	cout << "Chosen number of Bot(AI): ";
	cout << players;
	cout << "\n";
	//Sleep(100);

	Game_Manager GM = Game_Manager(players);
	cout << "Starting game... Please wait.\n";
	GM.Game();
	GM.Display_Results();

	cin >> PH;
}
