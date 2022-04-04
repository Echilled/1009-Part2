#include "Game_Manager.h"
#include<stdio.h>
#include<windows.h>
#include<MMsystem.h>
#include <string>
#include <iostream>
#include <thread>
#pragma comment( lib, "Winmm.lib" )
void play_music(int i) {
	try {
		PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	}
	catch (...) {
		cout << "No audio file found\n";
	}
 }
void play_music(float f) {
	try {
		PlaySound(TEXT("song2.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	catch (...) {
		cout << "No audio file found\n";
	}
}

int main() {
	int PH;
	int players = 5;
	std::thread t1([](auto var) { play_music(var); }, 1);
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
	std::thread t2([](auto var) { play_music(var); }, 1.0f);
	GM.Game();
	GM.Display_Results();

	cin >> PH;
	t1.join();
	t2.join();
	return 0;
}
