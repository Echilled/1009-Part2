#pragma once
#include <string>
#include <iostream>
#include "Information_store.h"
#include "Interactor.h"

using namespace std;


class Player: public Interactor, public Information_store {
private:
	friend class Game_Manager;
public:
	Player(int player_num, int round_num, int interact_num, string name);
	Player(int player_num, int round_num, int interact_num);

	virtual int make_decision() = 0; //depends on the class inheriting this class

	virtual ~Player() = 0;
};


