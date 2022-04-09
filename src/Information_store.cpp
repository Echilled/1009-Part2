#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "Information_store.h"


Information_store::Information_store(int max_player_num, int max_round_num, int max_interact_num) {
	this->max_player_num = max_player_num - 1;
	this->max_interaction_num = max_interact_num;
	this->max_round_num = max_round_num;
	this->points = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->decisions[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->self_decisions[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		this->playernames[i] = "Empty";
	}

}

Information_store::Information_store(int max_player_num, int max_round_num, int max_interact_num, string name) {
	this->name = name;

	this->max_player_num = max_player_num - 1;
	this->max_interaction_num = max_interact_num;
	this->max_round_num = max_round_num;
	this->points = 0;
	this->name = name;
	// this->name = this->randomise_name();

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->decisions[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k= 0; k < 100; k++) {
				this->self_decisions[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		this->playernames[i] = "Empty";
	}

}

int Information_store::get_points() {
	return this->points;
}
int Information_store::get_decision(int player, int round, int interact) {
	return this->decisions[player][round][interact];
}
int Information_store::get_self_decision(int player, int round, int interact) {
	return this->self_decisions[player][round][interact];
}

int Information_store::get_decision(string playername, int round, int interact) {
	for (int i = 0; i < this->max_player_num; i++) {
		if (!(playername.compare(this->playernames[i]))) {
			return this->get_decision(i, round, interact);
		}
	}
}
int Information_store::get_self_decision(string playername, int round, int interact) {
	for (int i = 0; i < this->max_player_num; i++) {
		if (!(playername.compare(this->playernames[i]))) {
			return this->get_self_decision(i, round, interact);
		}
	}
}

void Information_store::get_stats(int* self_cooperate_count, int* self_cheat_count, int* others_cooperate_count, int* others_cheat_count) {
	*self_cooperate_count = 0;
	*self_cheat_count = 0;
	*others_cooperate_count = 0;
	*others_cheat_count = 0;
	for (int i = 0; i < this->max_player_num-1; i++) {
		for (int j = 0; j < this->max_round_num; j++) {
			for (int k = 0; k < this->max_interaction_num; k++) {
				if (this->decisions[i][j][k] == 0) {
					*others_cheat_count += 1;
				}
				else if (this->decisions[i][j][k] == 1) {
					*others_cooperate_count += 1;
				}
				if (this->self_decisions[i][j][k] == 0) {
					*self_cheat_count += 1;
				}
				else if (this->decisions[i][j][k] == 1) {
					*self_cooperate_count += 1;
				}
			}
		}
	}
}

void Information_store::set_points(int points) {
	this->points = points;
}

void Information_store::set_opponent_decision(int decision, int player, int round, int interaction) {
	this->decisions[player][round][interaction] = decision;
}

void Information_store::set_opponent_decision(int decision, string playername, int round, int interaction) {
	int playernumber = -1;
	for (int i = 0; i < this->max_player_num; i++) {
		if (!playername.compare(this->playernames[i])) {
			//cout << "found sd: " << this->playernames[i] << endl;
			playernumber = i;
			break;
		}
	}
	if (playernumber == -1) {
		for (int i = 0; i < this->max_player_num; i++) {
			if (!this->playernames[i].compare("Empty")) {
				this->playernames[i] = playername;
				playernumber = i;
				//cout << "success sd: " << this->playernames[i] << endl;
				break;
			}
		}
	}
	if (playernumber == -1) {
		//cout << "An error occurred when setting decision sd\n";
		return;
	}
	this->set_opponent_decision(decision, playernumber, round, interaction);
}

void Information_store::set_self_decision(int decision, int player, int round, int interaction) {
	this->self_decisions[player][round][interaction] = decision;
}

void Information_store::set_self_decision(int decision, string playername, int round, int interaction) {
	int playernumber = -1;
	for (int i = 0; i < this->max_player_num; i++) {
		if (!playername.compare(this->playernames[i])) {
			playernumber = i;
			//cout << "found ssd: " << this->playernames[i] << endl;
			break;
		}
	}
	if (playernumber == -1) {
		for (int i = 0; i < this->max_player_num; i++) {
			if (!this->playernames[i].compare("Empty")) {
				this->playernames[i] = playername;
				playernumber = i;
				//cout << "success ssd: " << this->playernames[i] << endl;
				break;
			}
		}
	}
	if (playernumber == -1) {
		//cout << "An error occurred when setting decision ssd\n";
		//for (int i = 0; i < this->max_player_num; i++) {
			//cout << this->playernames[i] << " ";
		//}
		//cout << "\n";
		return;
	}

	this->set_self_decision(decision, playernumber, round, interaction);
}

void Information_store::print_decision_matrix(string name) {
	cout << "decisions made by " << name << ":\n";
	string decision_string[] = {"why", "cheat", "cooperate", "just in case 2", "just in case 3", "just in case 4"};
	for (int i = 0; i < this->max_round_num; i++) {
		cout << "Round " << i + 1 << endl;
		for (int j = 0; j < this->max_player_num; j++) {
			cout << "VS " << this->playernames[j] << ":" << endl;
			for (int k = 0; k < this->max_interaction_num; k++) {
				cout << "Interaction " << k+1 << ":\n";
				int opponent_decision = this->get_decision(j, i, k);
				int self_decision = this->get_self_decision(j, i, k);
				cout << ": You chose to: " << decision_string[self_decision] << endl;
				cout << ": Your opponent chose to: " << decision_string[opponent_decision] << endl;
			}
		}
	}
}

int Information_store::get_max_player_num() {
	return this->max_player_num;
}

int Information_store::get_max_round_num() {
	return this->max_round_num;
}

int Information_store::get_max_interaction_num() {
	return this->max_interaction_num;
}


string Information_store::get_name() {
	return this->name;
}
void Information_store::set_name(string name) {
	this->name = name;
}


const string NAME_FILE="textfiles/names.txt";

string* Information_store::read_names_from_file(){
	ifstream myFile;
	static string names[100]; // holds the 100 names in the file.
	// 
	try {
		myFile.open(NAME_FILE);
		cout << "open";
		int a = 0;
		string tmpString;
		 if(myFile.is_open()){
			while(getline(myFile, names[a])){ //read data from file object and put it into string.
					a++;
			}
		}else{
			throw "File not opened.";
		} 
	}
	catch (...) {
	  cout<< "Error reading "<<NAME_FILE<<" file."<<endl;
	}

	if(myFile.is_open()){ // check if file is still open and close it if it is.
		myFile.close();
	}
	
	return names;
}


string Information_store::randomise_name() {
	string a[] = {"Bob(AI)","Jack(AI)","Billy(AI)","Ginger(AI)","Gary(AI)"};
	return a[rand()%5];

	// string randomNames[20];// holds the randomly generated names FROM the file.
	// int randNum;

	// for (int i = 0; i < 20; i++) { // makes this program iterate 20 times; giving you 20 random names.
	// randNum = rand() % 1000 + 1; // gets a random number between 1, and 1000.
	// randomNames[i] = names[randNum]; 
	// }
	// for (int i = 0; i < 20; i++) {
	// cout << randomNames[i] << endl; // outputs all 20 names at once.
	// }

 //  return names[rand()%20];
}

