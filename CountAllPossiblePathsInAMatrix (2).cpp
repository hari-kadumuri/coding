#include <bits/stdc++.h>
using namespace std;

int PossiblePaths(int m, int n) {
	int count[m][n];
	for(int i=m-1;i>=0;i--) {
		for(int j=n-1;j>=0;j--) {
			if(i==m-1 || j==n-1)
				count[i][j] = 1;
			else
				count[i][j] = count[i+1][j] + count[i][j+1];
		}
	}
	return count[0][0];
}

int main(int argc, char const *argv[])
{
	int m = 2, n = 2;
	cout<<PossiblePaths(m, n)<<endl;
	return 0;
}