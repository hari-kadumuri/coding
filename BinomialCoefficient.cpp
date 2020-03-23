#include <bits/stdc++.h>
using namespace std;

int getBinomialCoefficient(int n, int k) {
	int opt[n+1][k+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=k && j<=i;j++) {
			if(j==0 || i==j)
				opt[i][j] = 1;
			else
				opt[i][j] = opt[i-1][j-1] + opt[i-1][j];
		}
	}
	return opt[n][k];
}

int main(int argc, char const *argv[])
{
	int n = 0, k = 0;
	cout<<getBinomialCoefficient(n, k)<<endl;
	return 0;
}