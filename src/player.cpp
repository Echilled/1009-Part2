#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Game_Manager.h"
#include "information_class.h"
#include "conversations.h"
using namespace std;

Player::Player(int player_num, int round_num, int interact_num, string name) : information_class(player_num, round_num, interact_num), Conversations(name){
}
Player::Player(int player_num, int round_num, int interact_num) : information_class(player_num, round_num, interact_num), Conversations() {
}

int Player::make_decision() {
	return 0;
}

Player::~Player() {}
