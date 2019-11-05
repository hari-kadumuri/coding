#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ifExists(int m, int n, int i, int j) {
	if(i>=0 && i<m && j>=0 && j<n)
		return 1;
	return 0;
}

int countPaths(int m, int n) {
	int opt[m][n];
	opt[m-1][n-1] = 1;
	for(int i=m-1;i>-1;i--) {
		for(int j=n-1;j>-1;j--) {
			if(i==m-1 && j==n-1)
				continue;
			opt[i][j] = 0;
			if(ifExists(m, n, i+1, j)) {
				opt[i][j] = (opt[i][j] + opt[i+1][j])%(1000000007);
			}
			if(ifExists(m, n, i, j+1)) {
				opt[i][j] = (opt[i][j] + opt[i][j+1])%(1000000007);
			}
		}
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			cout<<opt[i][j]<<" ";
		cout<<endl;
	}
	return opt[0][0];
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int m, n;
		cin>>m>>n;
		cout<<countPaths(m, n)<<endl;
	}
	return 0;
}