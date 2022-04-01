#pragma once
#include <string>
#include <iostream>
#include "player.h"
#include "scoreboard.h"
using namespace std;

class Player;

class Game_Manager {
private:
	int max_rounds = 5; //number of rounds
	int max_interact_rounds = 1; //number of times each individual interacts with per round

	int player_types = 5; //number of player types
	int number_of_players; //to be initialised during game
	int weights[5] = {1,1,1,1,1};//must be same length as described by player types
	//Player** players; //to be initialised during game
	Player* players[100];

	int cooperate_cost = 1; //cost of cooperating
	int cooperate_reward = 2; //reward for others cooperation
	scoreboard scoreboard;

public:
	Game_Manager(int NOP);
	void Interact(int p1, int p2, int round);
	void Game();
	void Display_Results();

	int* get_weights() {
		return this->weights;
	}
	int get_rounds() {
			return this->max_rounds;
		}
	int get_interact_rounds() {
			return this->max_interact_rounds;
	}
	int get_player_types() {
			return this->player_types;
	}
	int get_number_of_players() {
			return this->number_of_players;
	}

};
