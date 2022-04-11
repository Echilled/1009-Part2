#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "Game_Manager.h"
#include "Information_store.h"
#include "Interactor.h"
using namespace std;

Player::Player(int player_num, int round_num, int interact_num,string player_type,  string name) : Information_store(player_num, round_num, interact_num, name), Interactor(){
}
Player::Player(int player_num, int round_num, int interact_num, string player_type) : Information_store(player_num, round_num, interact_num), Interactor() {
}

int Player::make_decision(string, int, int) {
  return 0;
}

string Player::get_playerType(){
  return player_type;
}

Player::~Player() {}
