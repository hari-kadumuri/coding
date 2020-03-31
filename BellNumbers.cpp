#include <bits/stdc++.h>
using namespace std;

int BellNumbers(int n) {
	int opt[n+1][n+1]; // opt[i][j] denotes number of ways a set of i elements can be partitioned into j sets
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			if(i==j || j==1) opt[i][j] = 1;
			else
				opt[i][j] = opt[i-1][j-1]+j*opt[i-1][j];
		}
	}
	int count = 0;
	for(int i=1;i<=n;i++)
		count += opt[n][i];
	return count;
}

int main(int argc, char const *argv[])
{
	int n = 4;
	cout<<BellNumbers(n)<<endl;
	return 0;
}