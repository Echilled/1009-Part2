#include "Game_Manager.h"
#include <iostream>
int main() {
	int PH;
	int players = 10;
	cout << "number of players: ";

	try {
		while (!(cin >> players)) {
			continue;
		}
	}
	catch (...) {
		cout << "bad\n";
	}

	cout << "chosen number of players: ";
	cout << players;
	cout << "\n";
	//Sleep(100);

	Game_Manager GM = Game_Manager(players);
	cout << "starting game\n";
	GM.Game();
	GM.Display_Results();

	cin >> PH;
}
