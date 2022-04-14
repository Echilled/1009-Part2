#define NOMINMAX
#pragma comment(lib, "Winmm.lib")
#include "Game_Manager.h"
#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
#include <iostream>
#include <string>
#include <thread>

void play_music(int i) {
    try {
        PlaySound(TEXT("IDR_WAVE1"), GetModuleHandle(NULL), SND_RESOURCE |
        SND_ASYNC);
    }
    catch (...) {
        cout << "Audio failed to play\n";
    }
}
void play_music(float f) {
    try {
        PlaySound(TEXT("IDR_WAVE2"), GetModuleHandle(NULL), SND_RESOURCE |SND_ASYNC);
    }
    catch (...) {
        cout << "Audio failed to play\n";
    }
}

int main() {
    int PH;
    int players = 5;
    std::thread t1([](auto var) { play_music(var); }, 1);
    cout << "Choose number of Bot(AI) between 1 to 9: ";

    try {
        cin >> players;

        while (players > 9 || players < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "-------------------------" << endl;
            cout << "Please choose a number from 1 to 9." << endl;
            cout << "Choose number of Bot(AI) between 1 to 9: ";
            cin >> players;
            cout << "-------------------------" << endl;

        }
    }
    catch (...) {
        cout << "Error trying to get number of AI from user.\n";
        exit(0);
    }

    cout << "Chosen number of Bot(AI): " << players << endl;
    cout << "===============================" << endl;


    Game_Manager GM = Game_Manager(players);
    cout << "Starting game... Please wait.\n";
    std::thread t2([](auto var) { play_music(var); }, 1.0f);
    GM.Game();
    //GM.Display_Results();

    cin >> PH;
    t1.join();
    t2.join();
    return 0;
}
