#include "Game_Manager.h"
#include "player.h"
#include "PlayerTypes.cpp"
#include "scoreboard.h"
#include <iostream>
#include <stdio.h>
#include <iterator>



Game_Manager::Game_Manager(int NOP) {
	// cout << "check\n";
	srand(time(0));
	this->number_of_players = NOP;
	//this->players = (Player*)calloc(NOP, sizeof(Player*));
	//this->players = (Player**)calloc(NOP, sizeof(Player*));
};

void Game_Manager::Interact(int p1, int p2) {
	Player* player_1 = this->players[p1];
	Player* player_2 = this->players[p2];
  cout << "==================================================="<< endl;

	cout << "player: " << player_1->get_name() << " is interacting with " << player_2->get_name() << endl;

	for (int i = 0; i < this->max_interact_rounds; i++) {
		int p1_dec = player_1->make_decision(); // player
		int p2_dec = player_2->make_decision(); // bot

  
		player_1->set_points(player_1->get_points() + this->cooperate_reward * p2_dec - this->cooperate_cost*p1_dec);
		player_2->set_points(player_2->get_points() + this->cooperate_reward * p1_dec - this->cooperate_cost*p2_dec);
	}
}
/*
int Game_Manager::Interact(int p1, int p2) {
	Player player_1 = this->players[p1];
	Player player_2 = this->players[p2];

	for (int i = 0; i < this->max_interact_rounds; i++) {
		int p1_dec = player_1.make_decision();
		int p2_dec = player_2.make_decision();

		player_1.set_points(player_1.get_points() + this->cooperate_reward * p2_dec - this->cooperate_cost*p1_dec);
		player_2.set_points(player_2.get_points() + this->cooperate_reward * p1_dec - this->cooperate_cost*p2_dec);
	}
	return 0;
}*/

void Game_Manager::Game() {
	string Pname;
	string UserName;
	int Pscore;

	//Player* player_objects[5] = {&Random("P1"),&Random("P2"),&Random("P3"),&Random("P4"),&Random("P5")};
	//cout << "Random name: " << Random("name").get_name() << endl;
	cout << "Game has started\n";
	cout << "What is your name: ";
	cin >> UserName;
	(this->players)[0] = new User(this->number_of_players, this->max_rounds, this->max_interact_rounds, UserName);
	for (int i = 1; i < this->number_of_players; i++) {
		 cout << "choosing player " << i << "...\n";

		 //---------------------------------------
			int cumulative_weights[100];
			int sum = 0;
			int player_type_chosen;
			int random_number;

			for (int i = 0; i < this->player_types; i++) {
				sum += this->weights[i];
				cumulative_weights[i] = sum;
			}

			random_number = rand()%(sum);

			for (int i = 0; i < this->player_types; i++) {
				cout << "CRPT Cweight " << i << ": " << cumulative_weights[i] << endl;
			}

			for (int i = 0; i < this->player_types; i++) {
				if (random_number <= cumulative_weights[i]) {
					player_type_chosen = i;
					break;
				}
			}

			cout << "number chosen: " << random_number << ", player_type: " << player_type_chosen << endl;

			switch (player_type_chosen) {
			case 0:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			case 1:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			case 2:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			case 3:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			case 4:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			default:
				this->players[i] = new Random(this->number_of_players, this->max_rounds, this->max_interact_rounds);
				break;
			}
			cout << "player chosen: " << (this->players[i])->get_name() << "\n\n\n";
			/**/

		 //------------------------------------------
		 //this->players[i] = player_objects[rand()%5];
		 //this->choose_random_player_type((this->players)[i]);
		 //this->players[i] = chosen_player;
		 // ------------------------------------------------
		 cout << "printing info... \n";
		 Pname = this->players[i]->get_name();
		 //Pname = this->players[i].get_name();
		 cout << "name... ";
		 Pscore = this->players[i]->get_points();
		 //Pscore = this->players[i].get_points();
		 cout << "Player: " << Pname << "current score: " << Pscore << "...\n";

	}






	// Intialising the scoreboard
	for (int i = 0; i < this->number_of_players; i++) {
		scoreboard.initScoreMap(this->players[i]->get_name(), 0);
	}
	cout << scoreboard;

	for (int round = 0; round < this->max_rounds; round++) {
		cout << "===================================================" << endl;
    cout << "Round: " << round << endl;
		for (int i = 0; i < this->number_of_players; i++) {
			for (int j = i; j < this->number_of_players; j++) {
				if (i != j) {
					this->Interact(i,j);
				}
			}
			scoreboard.UpdateScore(this->players[i]->get_name(), this->players[i]->get_points()); // Accessing private variables as game manager is a friend
		}
	}
	cout << scoreboard;

}


void Game_Manager::Display_Results() {
	for (int i = 0; i < this->number_of_players; i++) {

		//tempstring = (char*)calloc(1000,sizeof(char));
		//sprintf(tempstring, "Player name: %s, Player score: %d", this->players[i]->get_name(), this->players[i]->get_points());
		cout << "Player name: " << this->players[i]->get_name() <<", Player score: " << this->players[i]->get_points() << "\n";
		//cout << "Player name: " << this->players[i].get_name() <<", Player score: " << this->players[i].get_points();


	}
  cout << "==================================================="<< endl;


}


