#include <bits/stdc++.h>
using namespace std;

int getnCr(int n, int r, int p) {
	int opt[n+1][r+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=r;j++) {
			if(i==j || j==0) opt[i][j] = 1;
			else opt[i][j] = (opt[i-1][j-1]+opt[i-1][j])%p;
		}
	return opt[n][r];
}

int main(int argc, char const *argv[])
{
	int n = 10, r = 2, p = 13;
	cout<<getnCr(n, r, p)<<endl;
	return 0;
}