#include "Game_Manager.h"
#include "player.h"
#include "Lifeline.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>


const int CHEAT = 1;
const int COOPERATE = 2;

class Random : public Player{
public:
  Random(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
      }
  Random(int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
      }

  int make_decision(string playername, int round, int interaction) override {
    int decision = (rand() % 2) + 1;
    return decision;
  }
};

class Angel : public Player{
public:
  Angel(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
      }
  Angel(int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
      }

  int make_decision(string playername, int round, int interaction) override {
    return COOPERATE;
  }
};

class Devil : public Player{
public:
	Devil(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
      }
	Devil (int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
      }

  int make_decision(string playername, int round, int interaction) override {
	  return CHEAT;
  }
};

class CopyCat : public Player{
public:
	CopyCat(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
      }
	CopyCat(int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
      }

  int make_decision(string playername, int round, int interaction) override {
	  if (interaction > 0) {
		  return this->get_decision(playername, round, interaction - 1);
	  } else if (round > 0) {
		  return this->get_decision(playername, round-1, this->get_max_interaction_num() - 1);
	  } else {
		  return COOPERATE;
	  }
	  return COOPERATE;
  }
};


class Hateful : public Player{
public:
	Hateful(int player_num, int round_num, int interact_num, string player_type, string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
      }
	Hateful(int player_num, int round_num, int interact_num, string player_type)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
      }

  int make_decision(string playername, int round, int interaction) override {
	  if (round + interaction == 0) {
		  return COOPERATE;
	  }
	  for (int i = 0; i < this->get_max_round_num(); i++) {
		  for (int j = 0; j < this->get_max_interaction_num(); j++) {
			  if (this->get_decision(playername, i, j) == -1) {
				  break;
			  }
			  if (this->get_decision(playername, i, j) == 1) {
                  return CHEAT;
			  }

		  }
	  }
	  return COOPERATE;
  }
};

class User : public Player{
public:
  User(int player_num, int round_num, int interact_num, string player_type,
       string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
        this->lifeline.set_lifeline_count(lifeline.get_lifeline_count());

      }
  User(int player_num, int round_num, int interact_num, string player_type,int lifeline_count)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
        this->lifeline.set_lifeline_count(lifeline_count);

      }

  int make_decision(string playername, int round, int interaction) override {
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
