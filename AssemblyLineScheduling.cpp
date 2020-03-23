#include <bits/stdc++.h>
using namespace std;

// 

int MinTimeToBuildChassis(int S[][4], int T[][4], int n) {
	int opt[2][n];
	opt[0][0] = S[0][0];
	opt[1][0] = S[1][0];
	for(int i=1;i<n;i++) {
		opt[0][i] = min(opt[0][i-1]+S[0][i], opt[1][i-1]+S[0][i]+T[1][i]);
		opt[1][i] = min(opt[1][i-1]+S[1][i], opt[0][i-1]+S[1][i]+T[0][i]);
	}
	for(int i=0;i<n;i++)
		cout<<opt[0][i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<opt[1][i]<<" ";
	cout<<endl;
	return min(opt[0][n-1], opt[1][n-1]);
}

int main(int argc, char const *argv[])
{
	int n = 4, S[][4] = {{10+4, 5, 3, 2+18}, {12+2, 10, 1, 4+7}}, T[][4] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
	T[0][0] = T[1][0] = 0;
	cout<<MinTimeToBuildChassis(S, T, n)<<endl;
	return 0;
}