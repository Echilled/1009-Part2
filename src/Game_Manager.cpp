#include "Game_Manager.h"
#include "PlayerTypes.cpp"
#include "player.h"
#include "scoreboard.h"
#include <iostream>
#include <iterator>
#include <stdio.h>

using namespace std;

Game_Manager::Game_Manager(int NOP) {
    srand(time(0));
    this->number_of_players = NOP;
};

void Game_Manager::Interact(int p1, int p2, int round, int interact) {
    Player* player_1 = this->players[p1];
    Player* player_2 = this->players[p2];

    int lifeline_count = player_1->lifeline.get_lifeline_count();
    cout << "===================================================" << endl;
    cout << "Interaction " << round + 1 << "/5: " << player_1->get_name()
        << " with " << player_2->get_name() << endl;

    if (!player_1->get_playerType().compare("User")) {
    	cout << player_2->get_name() << ": " << player_2->get_conversation() << endl;
    }
    if (!player_2->get_playerType().compare("User")) {
    	cout << player_1->get_name() << ": " << player_1->get_conversation() << endl;
    }

    int p1_dec = player_1->make_decision(player_2->get_name(), round, interact);
    int p2_dec = player_2->make_decision(player_1->get_name(), round, interact);

    do {
        if (p1_dec == 3) { // Player decision 3 = Lifeline
            int lifeline_decision;

            lifeline_decision = player_1->lifeline.lifeline_menu(lifeline_count);
            if (lifeline_decision == 1 &&
                lifeline_count > 0) { // Lifeline_decision 1: Reveal Type
                cout << "Lifeline 1 chosen: Reveal Bot(AI) Type" << endl;
                cout << player_2->get_name() << "'s player type is ["
                    << player_2->get_playerType() << "]" << endl;

                // Minus Score for using lifeline
                cout << "Deducting Score for using lifeline..." << endl;
                player_1->lifeline.minus_lifeline();
                lifeline_count = player_1->lifeline.get_lifeline_count();

            }
            else if (lifeline_decision == 2 &&
                lifeline_count >
                0) { // Lifeline_decision 2: AI Force Cooperate
                cout
                    << "Lifeline 2 chosen: Force current Bot(AI) to Cooperate with you."
                    << endl;
                cout << player_2->get_name() << " will now choose to Cooperate..."
                    << endl;
                p2_dec = 2;
                cout << "---------------------------------------------" << endl;

                // Minus Score for using lifeline
                cout << "Deducting Score for using lifeline..." << endl;
                player_1->lifeline.minus_lifeline();
                lifeline_count = player_1->lifeline.get_lifeline_count();

            }
            else if (lifeline_count == 0) {
                cout << "Not enough lifeline count. Unable to use lifeline." << endl;

            }
            else {
                cout << "Invalid lifeline selection." << endl;
            }
            // allow user to choose select actions after using lifeline
            p1_dec = player_1->make_decision(player_2->get_name(), round, interact);
        }

        if (p1_dec == 1) {   // Player decision 1 = cheats
            if (p2_dec == 1) { // BOT Cheats
                cout << player_1->get_name() << " chose to Cheat!" << endl;
                cout << player_2->get_name() << " chose to Cheat!" << endl;

            }
            else if (p2_dec == 2) { // BOT Cooperates
                cout << player_1->get_name() << " chose to Cheat!" << endl;
                cout << player_2->get_name() << " chose to Cooperate!" << endl;
                player_1->set_points(player_1->get_points() + 3);
                player_2->set_points(player_2->get_points() - 1);
            }

        }
        else if (p1_dec == 2) { // Player decision 2 = cooperate
            if (p2_dec == 1) {      // BOT Cheats
                cout << player_1->get_name() << " chose to Cooperate!" << endl;
                cout << player_2->get_name() << " chose to Cheat!" << endl;
                player_1->set_points(player_1->get_points() - 1);
                player_2->set_points(player_2->get_points() + 3);
            }
            else if (p2_dec == 2) { // BOT Cooperates
                cout << player_1->get_name() << " chose to Cooperate!" << endl;
                cout << player_2->get_name() << " chose to Cooperate!" << endl;
                player_1->set_points(player_1->get_points() + 1);
                player_2->set_points(player_2->get_points() + 1);
            }
        }
        cout << "---------------------------------------------" << endl;

    } while (p1_dec != 1 && p1_dec != 2);

    // Storing information for User
    this->players[p1]->set_self_decision(
        p1_dec, this->players[p2]->get_name(), round,
        interact); // stores decision made by user
    this->players[p1]->set_opponent_decision(
        p2_dec, this->players[p2]->get_name(), round,
        interact); // stores decision made by Bot(AI)

    // Storing information for Bot(AI)
    this->players[p2]->set_self_decision(
        p2_dec, this->players[p1]->get_name(), round,
        interact); // stores decision made by user
    this->players[p2]->set_opponent_decision(
        p1_dec, this->players[p1]->get_name(), round,
        interact); // stores decision made by Bot(AI)
}

template <typename T, typename U> void sortMap(map<T, U>& map) {
    cout << "this works";
}

void Game_Manager::Game() {
    string Pname;
    string UserName;
    int Pscore;

    string* ptr_to_namearray;
    ptr_to_namearray = Information_store::read_names_from_file(this->number_of_players);

    string* ptr_to_conversation_array;
    ptr_to_conversation_array = Interactor::read_conversations_from_file(this->number_of_players);

    cout << "Game has started\n";
    cout << "What is your name: ";
    cin >> UserName;
    (this->players)[0] = new User(this->number_of_players, this->max_rounds,
        this->max_interact_rounds, "User", UserName);

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

        random_number = rand() % (sum);
        // cout << "sum: " << sum << endl;
        // for (int i = 0; i < this->player_types; i++) {
        // cout << "CRPT Cweight " << i << ": " << cumulative_weights[i] << endl;
        //}

        for (int i = 0; i < this->player_types; i++) {
            if (random_number < cumulative_weights[i]) {
                player_type_chosen = i;
                break;
            }
        }

        switch (player_type_chosen) {
        case 0:
            this->players[i] = new Random(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "Random");
            break;
        case 1:
            this->players[i] = new Angel(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "Angel");
            break;
        case 2:
            this->players[i] = new Devil(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "Devil");
            break;
        case 3:
            this->players[i] = new CopyCat(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "CopyCat");
            break;
        case 4:
            this->players[i] = new Hateful(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "Hateful");
            break;
        default:
            this->players[i] = new Random(this->number_of_players, this->max_rounds,
                this->max_interact_rounds, "CaseDefault");
            break;
        }

        this->players[i]->set_name(ptr_to_namearray[i]);
        this->players[i]->set_conversation(ptr_to_conversation_array[i]);

        cout << "------------------------" << endl;
        cout << "player chosen: " << (this->players[i])->get_name() << "\n\n\n";

        cout << "printing info... \n";
        Pname = this->players[i]->get_name();

        // cout << "name... ";
        Pscore = this->players[i]->get_points();
        string Ptype = this->players[i]->get_playerType();

        cout << "Player: " << Pname << "\nCurrent score: " << Pscore
            << " \nPlayer type: " << Ptype << "...\n";
        cout << "------------------------" << endl;
    }

    // Intialising the scoreboard
    for (int i = 0; i < this->number_of_players; i++) {
        scoreboard.initScoreMap(this->players[i]->get_name(), 0);
    }
    cout << scoreboard;

    for (int round = 0; round < this->max_rounds; round++) {
        cout << "===================================================" << endl;
        cout << "Beginning Interactions, Round: " << round + 1 << endl;
        for (int i = 0; i < this->number_of_players; i++) {
            for (int j = i; j < this->number_of_players; j++) {
                if (i != j) {
                    for (int k = 0; k < this->max_interact_rounds; k++) {
                        this->Interact(i, j, round, k);
                    }
                }
            }
            scoreboard.UpdateScore(
                this->players[i]->get_name(),
                this->players[i]->get_points()); // Accessing private variables as
                                                 // game manager is a friend
        }
    }
    cout << scoreboard;
}

void Game_Manager::Display_Results() {
    for (int i = 0; i < this->number_of_players; i++) {

        // tempstring = (char*)calloc(1000,sizeof(char));
        // sprintf(tempstring, "Player name: %s, Player score: %d",
        // this->players[i]->get_name(), this->players[i]->get_points());
        cout << "Player name: " << this->players[i]->get_name()
            << ", Player score: " << this->players[i]->get_points() << "\n";
        // cout << "Player name: " << this->players[i].get_name() <<", Player score:
        // " << this->players[i].get_points();
    }
    cout << "===================================================" << endl;
    cout << "END OF GAME" << endl;
    exit(0);
}
