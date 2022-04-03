#include "Game_Manager.h"
#include<stdio.h>
#include<windows.h>
#include<MMsystem.h>
#include <string>
#include <iostream>
#include <thread>
#pragma comment( lib, "Winmm.lib" )
void play_music() {
	try {
		PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	}
	catch (...) {
		cout << "No audio file found\n";
	}
 }

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

	std::thread t(play_music);
	cout << "Chosen number of Bot(AI): ";
	cout << players;
	cout << "\n";
	//Sleep(100);

	Game_Manager GM = Game_Manager(players);
	cout << "Starting game... Please wait.\n";
	GM.Game();
	GM.Display_Results();

	cin >> PH;
	t.join();
	return 0;
}
