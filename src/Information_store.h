#pragma once
#include <string>
#include <iostream>

using namespace std;

class Information_store {
private:
	int points;
	int decisions[100][100][100];
	string playernames[100];

	int max_player_num;
	int max_round_num;
	int max_interaction_num;
	friend class Game_Manager;

public:
	Information_store(int max_player_num, int max_round_num, int max_interact_num);
	int get_points();
	int get_decision(int player, int round, int interactions);
	int get_decision(string playername, int round, int interactions);
	int*** get_decision_array();

	void set_points(int points);
	void set_decision(int decision, int player, int round, int interaction);
	void set_decision(int decision, string playername, int round, int interaction);


};
