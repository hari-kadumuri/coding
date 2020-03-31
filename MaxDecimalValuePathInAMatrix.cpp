#include <bits/stdc++.h>
using namespace std;

int getMaxDecimalValue(int a[4][4], int n) {
	int val[n][n];
	for(int i=n-1;i>=0;i--) {
		for(int j=n-1;j>=0;j--) {
			if(i==n-1 && j==n-1)
				val[i][j] = a[i][j];
			else if(i==n-1)
				val[i][j] = val[i][j+1]+(a[i][j]?pow(2, n-i+n-j-2):0);
			else if(j==n-1)
				val[i][j] = val[i+1][j]+(a[i][j]?pow(2, n-i+n-j-2):0);
			else {
				if(val[i+1][j]>val[i][j+1])
					val[i][j] = val[i+1][j]+(a[i][j]?pow(2, n-i+n-j-2):0);
				else
					val[i][j] = val[i][j+1]+(a[i][j]?pow(2, n-i+n-j-2):0);
			}
		}
	}
	return val[0][0];
}

int main(int argc, char const *argv[])
{
	int a[4][4] = {{1, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 1, 1}};
	cout<<getMaxDecimalValue(a, 4)<<endl;
	return 0;
}