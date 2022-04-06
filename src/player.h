#pragma once
#include <string>
#include <iostream>
#include "Information_store.h"
#include "Interactor.h"
#include "Lifeline.h"

using namespace std;


class Player: public Interactor, public Information_store, public Lifeline{
private:
	friend class Game_Manager;

protected:  
  string player_type;

public:
	Player(int player_num, int round_num, int interact_num, string player_type, string name);
	Player(int player_num, int round_num, int interact_num, string player_type);
  
  string get_playerType();
	virtual int make_decision(string, int, int) = 0; //depends on the class inheriting this class

	virtual ~Player() = 0;
};


