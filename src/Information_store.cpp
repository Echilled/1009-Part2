#include <stdio.h>
#include <stdlib.h>

#include "Information_store.h"

Information_store::Information_store(int max_player_num, int max_round_num, int max_interact_num) {
	this->max_player_num = max_player_num;
	this->max_interaction_num = max_interact_num;
	this->max_round_num = max_round_num;
	this->points = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->decisions[i][j][k] = -1;
			}
		}
	}

}
int Information_store::get_points() {
	return this->points;
}

int Information_store::get_decision(int player, int round, int interact) {
	return this->decisions[player][round][interact];
}

void Information_store::set_points(int points) {
	this->points = points;
}

void Information_store::set_decision(int decision, string playername, int round, int interaction) {
	int playernumber = 0;
	this->decisions[playernumber][round][interaction] = decision;
}

