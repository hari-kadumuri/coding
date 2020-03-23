#include <bits/stdc++.h>
using namespace std;

bool ifexists(int i, int j, int m, int n) {
	return (0<=i && i<m && 0<=j && j<n);
}

int getMaxSquareSize(bool a[6][5], int m, int n) {
	int opt[m][n];
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			if(a[i][j]==false)
				opt[i][j] = 0;
			else {
				int y = min((ifexists(i-1, j-1, m, n)?opt[i-1][j-1]:INT_MAX), min((ifexists(i-1, j, m, n)?opt[i-1][j]:INT_MAX), (ifexists(i, j-1, m, n)?opt[i][j-1]:INT_MAX)));
				opt[i][j] = 1+(y==INT_MAX?0:y);
			}
		}
	}
	int maxval = -1;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			maxval = max(maxval, opt[i][j]);
			cout<<opt[i][j]<<" ";
		}
		cout<<endl;
	}
	return maxval;
}

int main(int argc, char const *argv[])
{
	bool mat[6][5] = {{false, true, true, false, true},
						{true, true, false, true, false},
						{false, true, true, true, false},
						{true, true, true, true, false},
						{true, true, true, true, true},
						{false}};
	cout<<getMaxSquareSize(mat, 6, 5)<<endl;
	return 0;
}