#include <stdio.h>
#include <stdlib.h>

#include "information_class.h"

information_class::information_class(int player_num, int round_num, int interact_num) {
	this->points = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->decisions[i][j][k] = -1;
			}
		}
	}
	this->player_num = player_num;
	this->interaction_num = interact_num;
	this->round_num = round_num;

}
int information_class::get_points() {
	return this->points;
}
int information_class::get_decision(int player, int round, int interact) {
	return this->decisions[player][round][interact];
}

void information_class::set_points(int points) {
	this->points = points;
}
void information_class::set_decision(int decision, string playername, int round, int interaction) {
	int playernumber;
	this->decisions[playernumber][round][interaction] = decision;
}

/*
string Information_class::get_name() {
	return this->name;
}
string Information_class::get_conversation() {
	return this->conversation;
}
void Information_class::set_name(string name) {
	this->name = name;
}
void Information_class::set_conversation(string conversation) {
	this->conversation = conversation;
}
*/





