#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubString(string x, string y) {
	int opt[x.size()+1][y.size()+1];
	for(int i=0;i<=x.size();i++) {
		for(int j=0;j<=y.size();j++)
			opt[i][j] = 0;
	}
	for(int i=1;i<=x.size();i++) {
		for(int j=1;j<=y.size();j++) {
			if(x[i-1]==y[j-1])
				opt[i][j] = 1+opt[i-1][j-1];
			else
				opt[i][j] = 0;
		}
	}
	int max = 0;
	for(int i=0;i<=x.size();i++)
		for(int j=0;j<=y.size();j++)
			max = (max<opt[i][j]?opt[i][j]:max);
	return max;
}

int main() {
	string x, y;
	// cin>>x>>y;
	x = "abcdxyz";
	y = "xyzabcd";
	cout<<LongestCommonSubString(x, y)<<endl;
	return 0;
}