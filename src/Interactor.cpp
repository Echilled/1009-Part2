#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Interactor.h"
#include <algorithm>

const string CONVERSATIONS_FILE = "textfiles\\conversations.txt";
const int MAX = 100;
const int MAX_RAND = 10;


Interactor::Interactor() {
	this->conversation = this->randomise_conversation();
}

string Interactor::randomise_conversation() {
	return "hello world";
}



string Interactor::get_conversation() {
	return this->conversation;
}
void Interactor::set_conversation(string conversation) {
	this->conversation = conversation;
}

string* Interactor::read_conversations_from_file(int num_of_AI) {
	ifstream myFile;
	static string conversations[MAX]; // holds the 100 names in the file.
	static string rand_conversations[MAX_RAND]; // contains the random names to be return back

	int a = 0;

	try {
		myFile.open(CONVERSATIONS_FILE);

		string tmpString;
		if (myFile.is_open()) {
			while (getline(
				myFile,
				conversations[a])) { // read data from file object and put it into string.
				a++;
			}
		}
		else {
			throw "File not opened.";
		}
	}
	catch (...) {
		cout << "Error reading " << CONVERSATIONS_FILE << " file." << endl;
	}

	if (myFile.is_open()) { // check if file is still open and close it if it is.
		myFile.close();
	}


	int assigned_count = 0;
	//ensure all AI needed are assigned a name
	while (assigned_count < num_of_AI) {
		string tmp_conversations = conversations[rand() % a];

		//checks if the AI name already exists in the Array
		if (in_array(tmp_conversations, rand_conversations) == 0) {
			//if not found in array, assigned the name
			rand_conversations[assigned_count] = tmp_conversations;
			assigned_count++;
		}
		else {
			//get a new random name to try again
			tmp_conversations = conversations[rand() % (a - 1)];
		}
	}

	for (int i = 0; i < num_of_AI; i++) {
		//cout << "CONVERSATIONS: " << rand_conversations[i] << endl;
	}

	return rand_conversations;
}

bool Interactor::in_array(string string_to_check, string* ptr_to_array) {
	bool found = false;

	for (int i = 0; i < MAX_RAND; ++i) {

		if ((ptr_to_array[i]).compare(string_to_check) == 0) {
			found = true;
			return found;
		}
	}
	return found;

}
