#include <bits/stdc++.h>
using namespace std;

int coinChange(int S[], int m, int n) {
	int opt[m][n+1];
	for(int i=0;i<m;i++) {
		for(int j=0;j<=n;j++) {
			if(j==0)
				opt[i][j] = 1;
			else if(i==0)
				opt[i][j] = (j%S[0]==0?1:0);
			else
				opt[i][j] = (j>=S[i]?opt[i][j-S[i]]:0)+opt[i-1][j];
		}
	}
	return opt[m-1][n];
}

int main(int argc, char const *argv[])
{
	int m = 3, n = 4, S[m] = {1, 2, 3};
	cout<<coinChange(S, m, n)<<endl;
	return 0;
}