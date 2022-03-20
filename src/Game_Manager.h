#pragma once
#include "player.h"
#include "scoreboard.h"
#include <string>
#include <iostream>
using namespace std;

class Game_Manager {
private:
	int max_rounds = 5; //number of rounds
	int max_interact_rounds = 2; //number of times each individual interacts with per round

	int player_types = 5; //number of player types
	int number_of_players; //to be initialised during game
	int weights[5] = {1,1,1,1,1};//must be same length as described by player types
	Player* players[100];
	//Player** players; //to be initialised during game

	int cooperate_cost = 1; //cost of cooperating
	int cooperate_reward = 2; //reward for others cooperation
	scoreboard scoreboard;

public:
	Game_Manager(int NOP);
	int Interact(int p1, int p2);
	void Game();
	void choose_random_player_type(Player *player);
	void Display_Results();
};
