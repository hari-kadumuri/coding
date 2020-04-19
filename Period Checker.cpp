#include <bits/stdc++.h>
using namespace std;

vector<int> parseFile(string filename) {
	ifstream myfile;
	myfile.open("PeriodFile.txt");
	vector<int> arr;
	string line;
	while(getline(myfile, line)) {
		for(auto x: line) {
			if(x=='0' || x=='1' || x=='2')
				arr.push_back(x-'0');
		}
	}
	return arr;
}

int getPeriod(vector<int>&
 arr, int limit) {
	int minperiod = 1, period = 1;
	double error = 1;
	while(period<=limit) {
		double temperror = 0;
		for(int i=period;i<arr.size();i++) {
			temperror += (int)!(arr[i]==arr[i-period]);
		}
		temperror = temperror/arr.size();
		if(temperror<error) {
			error = temperror;
			minperiod = period;
		}
		cout<<period<<", "<<minperiod<<", "<<temperror<<endl;
		period++;
	}
	return minperiod;
}

int main(int argc, char const *argv[])
{
	string filename = "in.csv";
	vector<int> arr = parseFile(filename);
	int limit = 30;
	for(auto x: arr)
		cout<<x<<" ";
	cout<<endl;
	cout<<getPeriod(arr, min(limit, (int)arr.size()))<<endl;
	return 0;
}