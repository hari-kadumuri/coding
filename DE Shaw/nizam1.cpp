#include <bits/stdc++.h>
using namespace std;

int distributingstones(vector<int> planets) {
	int moves = 0, stones = 0;
	for(int i=0;i<planets.size();i++) {
		stones += planets[i];
		// requirement++;
		if(stones!=i+1)
			moves++;
		// cout<<stones<<" "<<requirement<<" "<<moves<<endl;
	}
	return moves;
}

int main(int argc, char const *argv[])
 {
	vector<int> planets;
	planets.push_back(0);
	planets.push_back(0);
	planets.push_back(0);
	planets.push_back(3);
	planets.push_back(1);
	planets.push_back(2);
	// planets.push_back(0);
	cout<<distributingstones(planets)<<endl;
	return 0;
}