#include <string>
#include <iostream>
#include "scoreboard.h"
#include "player.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;


scoreboard::scoreboard(){
	cout << "This is the scoreboard constructor"<< endl;
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


struct comp {
    template <typename T>
    // Comparator function
    bool operator()(const T& l,
                    const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};


std::ostream& operator<<(ostream& out, const scoreboard& scoreboard) {
  out << "===================================================" << endl;
  out << "Scoreboard:\n";
  set<pair<string, int>, comp> S(scoreboard.score_map.begin(),
		  scoreboard.score_map.end());
   for (auto& it : S) {
          out << it.first << ' '
               << it.second << endl;
      }

	return out;
}
