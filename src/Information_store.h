#pragma once
#include <string>
#include <iostream>

using namespace std;

class Information_store {
private:
	int points;
	int decisions[100][100][100];
	int self_decisions[100][100][100];
	string playernames[100];

	int max_player_num;
	int max_round_num;
	int max_interaction_num;
	friend class Game_Manager;

public:
	Information_store(int max_player_num, int max_round_num, int max_interact_num);
	int get_points();

	int get_max_player_num();
	int get_max_round_num();
	int get_max_interaction_num();

	int get_decision(int player, int round, int interactions);
	int get_decision(string playername, int round, int interactions);
	int get_self_decision(int player, int round, int interactions);
	int get_self_decision(string playername, int round, int interactions);

	void get_stats(int* self_cooperate_count, int* self_cheat_count, int* others_cooperate_count, int* others_cheat_count);

	void set_points(int points);
	void set_opponent_decision(int decision, int player, int round, int interaction);
	void set_opponent_decision(int decision, string playername, int round, int interaction);
	void set_self_decision(int decision, int player, int round, int interaction);
	void set_self_decision(int decision, string playername, int round, int interaction);

	void print_decision_matrix(string name);
};
