

#include <string>
#include <iostream>
#include "scoreboard.h"
#include "player.h"
#include <iterator>

using namespace std;

scoreboard::scoreboard(){
	cout << "this is the scoreboard constructor";
}


map<string, int> scoreboard::getScoreMap(){
	return this->score_map;
}

void initScoreMap(string playername, int player_points){ // Initializing the score map

}


void scoreboard::UpdateScore(string playername, int player_points){

}

void scoreboard::displayScoreMap(){
	map<string, int>::iterator itr;
	cout << "Score map:" <<endl;
	 for (itr = this->score_map.begin(); itr != this->score_map.end(); ++itr) {
	        cout << '\t' << itr->first << '\t' << itr->second
	             << '\n';
	    }
}
