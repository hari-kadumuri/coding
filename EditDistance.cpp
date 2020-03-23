#include <bits/stdc++.h>
using namespace std;

int getDist(string s1, string s2) {
	int dist[s1.size()+1][s2.size()+1];
	for(int i=0;i<s1.size()+1;i++) {
		for(int j=0;j<s2.size()+1;j++) {
			if(i==0 || j==0)
				dist[i][j] = i+j;
			else {
				if(s1[i]==s2[j])
					dist[i][j] = dist[i-1][j-1];
				else
					dist[i][j] = 1+min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]));
			}
		}
	}
	return dist[s1.size()][s2.size()];
}

int main(int argc, char const *argv[])
{
	string s1 = "sunday", s2 = "saturday";
	cout<<getDist(s1, s2)<<endl;
	return 0;
}