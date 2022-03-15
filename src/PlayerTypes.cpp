#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

class Random: public Player {
private:
public:
	Random(string name): Player(name) {}
	int make_decision() override {
		int decision = rand()%2;
		//do something
		this->set_decision(decision);
		return decision;
	}
};
