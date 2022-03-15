#pragma once
#include <iostream>
using namespace std;

class Player {
private:
	int points;
	string name;
	int previous_decision;
public:
	Player(string name);

	int get_points();
	void set_points(int points);

	int get_decision();
	void set_decision(int decision);

	string get_name();
	void set_name(string name);

	virtual int make_decision() = 0; //depends on the class inheriting this class
	virtual ~Player() = 0;
};
