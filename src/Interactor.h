#pragma once
#include <string>
#include <iostream>

using namespace std;

class Interactor {
private:
	string conversation;
	friend class Game_Manager;
public:
	Interactor();
	Interactor(string name);

	string get_conversation();
	string randomise_conversation();
	void set_conversation(string conversation);

	static string* read_conversations_from_file(int num_of_AI);
	static bool in_array(string string_to_check, string* ptr_to_array);
};
