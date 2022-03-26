#pragma once
#include <string>
#include <iostream>

using namespace std;

class Conversations {
private:
	friend class Game_Manager;
	string name;
	string conversation;
public:
	Conversations();
	Conversations(string name);

	string get_name();
	string get_conversation();

	string randomise_name();
	string randomise_conversation();

	void set_name(string name);
	void set_conversation(string conversation);
};
