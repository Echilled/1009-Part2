#include "Game_Manager.h"
#include "player.h"
#include "Lifeline.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

class Random : public Player{
public:
  Random(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;
      }
  Random(int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;
      }

  int make_decision() override {
    int decision = rand() % 2;
    return decision;
  }
};

class User : public Player{
public:
  User(int player_num, int round_num, int interact_num, string player_type,
       string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;

      }
  User(int player_num, int round_num, int interact_num, string player_type,int lifeline_count)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;

      }

  int make_decision() override {
    int decision;
    do {
      cout << "===================================================" << endl;
      cout << "1 - Cheat\n"
           << "2 - Cooperate\n"
           << "3 - Use Lifeline\n"
           << "User input required: ";
      cin >> decision;
      if (decision > 3 || decision < 1) {
        cout << "Invalid Option. Please choose the following options again."
             << endl;
      }
    } while (decision != 1 && decision != 2 && decision != 3);
    return decision;
  }
};
