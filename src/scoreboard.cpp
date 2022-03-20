

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

void scoreboard::initScoreMap(string playername, int player_points = 0){ // Initializing the score map
	this->score_map.insert({ playername, player_points });
}


void scoreboard::UpdateScore(string playername, int player_points){
	std::map<string, int>::iterator it = this->score_map.find(playername);
	if (it != this->score_map.end())
	    it->second = player_points;
}

void scoreboard::displayScoreMap(){
	map<string, int>::iterator itr1;
	cout << "Score map:" <<endl;
	 for (itr1 = this->score_map.begin(); itr1 != this->score_map.end(); ++itr1) {
	        cout << '\t' << itr1->first << '\t' << itr1->second << '\n';
	    }
}
