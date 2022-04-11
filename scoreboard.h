/*
 * scoreboard.h
 *
 *  Created on: 19 Mar 2022
 *      Author: Eugene Chew
 */

#include "player.h"
#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include <map>

using namespace std;

class scoreboard{

private:
	map<string, int> score_map; //Dictionary to store the player name with the player score

public:
	scoreboard();
	map<string, int> getScoreMap();
	void initScoreMap(string, int);
	void UpdateScore(string, int);
	void displayScoreMap();
	friend ostream& operator<<(ostream& out, const scoreboard& scoreboard);

};




#endif /* SCOREBOARD_H_ */
