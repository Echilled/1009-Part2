#pragma once
#include <string>
#include <iostream>

using namespace std;

class Interactor {
private:
	string conversation;
	string action;
public:
	Interactor();
	Interactor(string name);

	string get_conversation();
	string randomise_conversation();
	void set_conversation(string conversation);
};
