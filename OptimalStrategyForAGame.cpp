// We have an array of integers. This two player game is select any value on the either side of the array to be removed. The removed value will be added to
// that person's score. Then the second person will get the turn to do the same. The process repeats until the array is empty. The following code
// returns the maximum value you can get by selecting given the user gets the first turn. Note that the both players are of same intellect and can reason
// upto any level of logic.

// The following is the DP code that uses memoization

#include <bits/stdc++.h>
using namespace std;

void print(int** opt, int m, int n) {
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			cout<<opt[i][j]<<" ";
		cout<<endl;
	}
}

int fill(int a[], int** sum, int** opt, int i, int j, int n) {
	if(i==j || i==n-1) {
		opt[i][j] = a[i];
		return a[i];
	}
	if(opt[i][j]!=-1) return opt[i][j];
	opt[i][j] = max(a[i]+sum[i+1][j]-fill(a, sum, opt, i+1, j, n), a[j]+sum[i][j-1]-fill(a, sum, opt, i, j-1, n));
	return opt[i][j];
}

int getMaxVal(int a[], int n, int** opt) {
	// opt[i][j] = max(a[i]+sum[i+1][j]-opt[i+1][j], a[j]+sum[i][j-1]-opt[i][j-1])
	int** sum = new int*[n];
	for(int i=0;i<n;i++) {
		sum[i] = new int[n];
		for(int j=0;j<n;j++) {
			if(i==j)
				sum[i][j] = a[i];
			else if(j>i)
				sum[i][j] = sum[i][j-1]+a[j];
			else
				sum[i][j] = sum[j][i];
			opt[i][j] = -1;
		}
	}
	fill(a, sum, opt, 0, n-1, n);
	for(int i=0;i<n;i++)
		delete sum[i];
	delete sum;
	return opt[0][n-1];
}

int main(int argc, char const *argv[])
{
	int n = 4, a[n] = {7, 3, 15, 8};
	int** opt = new int*[n];
	for(int i=0;i<n;i++)
		opt[i] = new int[n];
	cout<<getMaxVal(a, n, opt)<<endl;
	for(int i=0;i<n;i++)
		delete opt[i];
	delete opt;
	return 0;
}