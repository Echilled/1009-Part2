#pragma once
#include <string>
#include <iostream>

using namespace std;

class Interactor {
private:
	string name;
	string conversation;
	string action;
public:
	Interactor();
	Interactor(string name);

	string get_name();
	string get_conversation();

	string randomise_name();
	string randomise_conversation();

	void set_name(string name);
	void set_conversation(string conversation);
};
