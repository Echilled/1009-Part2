#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "information_class.h"
#include "Game_Manager.h"

class Random: public Player {
private:
public:
	Random(int player_num, int round_num, int interact_num, string name): Player(player_num, round_num, interact_num, name) {}
	Random(int player_num, int round_num, int interact_num): Player(player_num, round_num, interact_num) {}
	int make_decision() override {
		int decision = rand()%2;
		//do something
		return decision;
	}
};

class User: public Player {
private:
public:

	User(int player_num, int round_num, int interact_num, string name): Player( player_num, round_num, interact_num, name) {

	}
	User(int player_num, int round_num, int interact_num): Player(player_num, round_num, interact_num) {

	}

	int make_decision() override {
		int decision;
		cout << "User input required: ";
		cin >> decision;
		return decision;
	}

};
