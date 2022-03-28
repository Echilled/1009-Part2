#include "Game_Manager.h"
#include "player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>


class Random : public Player {
private:
public:
  Random(int player_num, int round_num, int interact_num, string name)
      : Player(player_num, round_num, interact_num, name) {}
  Random(int player_num, int round_num, int interact_num)
      : Player(player_num, round_num, interact_num) {}
  int make_decision() override {
    int decision = rand() % 2;

    // do something
    return decision;
  }
};

class User : public Player {
private:

public:
  User(int player_num, int round_num, int interact_num, string name)
      : Player(player_num, round_num, interact_num, name) {}
  User(int player_num, int round_num, int interact_num)
      : Player(player_num, round_num, interact_num) {}

  int make_decision() override {
     int decision;
    do {
        cout << "==================================================="<< endl;
        cout << "1 - Cheat\n" << "2 - Cooperate\n" << "3 - Use Lifeline\n" << "User input required: ";
          cin >> decision;
          if (decision > 3 || decision < 1) {
              cout << "Invalid Option. Please choose the following options again." << endl;
          }
      } while (decision != 1 && decision != 2 && decision != 3);
     
    return decision;
  }
};
