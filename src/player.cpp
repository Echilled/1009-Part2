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

Player::Player(int player_num, int round_num, int interact_num, string name) : Information_store(player_num, round_num, interact_num), Interactor(name){
}
Player::Player(int player_num, int round_num, int interact_num) : Information_store(player_num, round_num, interact_num), Interactor() {
}

int Player::make_decision() {
  return 0;
}


int Player::get_lifeline_count(){
  return lifeline_count;
}


void Player::minus_lifeline(){
  if (this->lifeline_count >0){
    this->lifeline_count--;
  }else{
    cout << "No more Lifeline. No lifeline given..." << endl;
  }
}

Player::~Player() {}
