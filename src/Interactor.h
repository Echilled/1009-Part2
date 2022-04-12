#pragma once
#include <string>
#include <iostream>

using namespace std;

class Interactor {
private:
	string conversation;
public:
	Interactor();
	Interactor(string name);

	string get_conversation();
	string randomise_conversation();
	void set_conversation(string conversation);

	string* read_conversations_from_file(int num_of_AI);
	bool in_array(string string_to_check, string* ptr_to_array);
};
