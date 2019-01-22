// Galey Shapley
// from https://rosettacode.org/wiki/Stable_marriage_problem#C.2B.2B

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;


const char *men_data[][4] = {
	{"M_een", "V_een", "V_twee", "V_drie"},
	{"M_twee", "V_drie", "V_twee", "V_een"},
	{"M_drie", "V_twee", "V_een", "V_drie"},
};


const char *women_data[][4] = {
	{"V_een", "M_een", "M_twee", "M_drie"},
	{"V_twee", "M_drie", "M_twee", "M_een"},
	{"V_drie", "M_twee", "M_een", "M_drie"},
};


// Does "first" appear before "second" in preference list?
bool prefers(const vector<string> &preferlist, const string &first, const string &second){
	for(auto it = preferlist.begin(); it != preferlist.end(); ++it){
		if (*it == first) return true;
		if (*it == second) return false;
	}
	return false; // no preference
}


// check
void check_stability(const map<string, string> engaged_couples, const map<string, vector<string>> &men_pref, const map<string, vector<string>> &women_pref) {
	cout << "Checking stability:\n" << endl;
	bool stable = true;
	// todo ...
}


int main() {


	map<string, vector<string>> men_pref, women_pref;
	queue<string> bachelors;

	// push data from data to pref maps
	for (int i = 0; i < 4; ++i) { // person
		for (int j = 1; j < 11; ++j) { // preference
			men_pref[men_data[i][0]].push_back(men_data[i][j]);
			women_pref[women_data[i][0]].push_back(women_data[i][j]);
		}
		bachelors.push(men_data[i][0]);
	}


	// algo

	vector<string, string> couples; //woman, men

	cout << "Algo\n" << endl;

	while(!bachelors.empty()){
		const string &suitor = bachelors.front();
		const vector<string> &preflist = men_pref[suitor];

		for (auto it = preflist.begin(); it != preflist.end() ++i) {
			const string &bride = *it;

			if(engaged.find(bride) == engaged.end()){
				// she is available
				engaged[bride] = suitor;
				break;
			}

			if(prefers)
		}
	}

	return 0;
}