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
    return 2;
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
	  return 1;
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
		  return this->get_decision(playername, round, this->get_max_interaction_num() - 1);
	  } else {
		  return 2;
	  }
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
	  int decision = 2;
	  if (round + interaction == 0) {
		  return decision;
	  }
	  for (int i = 0; i < this->get_max_round_num(); i++) {
		  for (int j = 0; j < this->get_max_interaction_num(); j++) {
			  if (this->get_decision(playername, i, j) == -1) {
				  break;
			  }
			  if (this->get_decision(playername, i, j) == 1) {
			  	  decision = 1;
			  	  break;
			  }

		  }
	  }
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

class User2 : public Player{
public:
  User2(int player_num, int round_num, int interact_num, string player_type,
       string name)
      : Player(player_num, round_num, interact_num, player_type, name){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;

      }
  User2(int player_num, int round_num, int interact_num, string player_type,int lifeline_count)
      : Player(player_num, round_num, interact_num, player_type){
        this->player_type = player_type;
        this->lifeline_count = lifeline_count;

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
      if (decision== 3) { // Player decision 3 = Lifeline
              int lifeline_decision;
              lifeline_decision = this->lifeline_menu(lifeline_count);
              this->set_lifeline_selection(lifeline_decision);
      }

    } while (decision != 1 && decision != 2 && decision != 3);
    return decision;
  }
};
