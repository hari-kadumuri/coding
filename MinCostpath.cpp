#include <bits/stdc++.h>
using namespace std;

bool ifexists(int i, int j, int m, int n) {
	return (0<=i && i<m && 0<=j && j<n);
}

int MinCostPath(int a[3][3], int m, int n) {
	int cost[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) {
			int y = min((ifexists(i-1, j-1, m, n)?cost[i-1][j-1]:INT_MAX), min((ifexists(i-1, j, m, n)?cost[i-1][j]:INT_MAX), (ifexists(i, j-1, m, n)?cost[i][j-1]:INT_MAX)));
			cost[i][j] = a[i][j]+(y==INT_MAX?0:y);
		}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			cout<<cost[i][j]<<" ";
		cout<<endl;
	}
	return cost[m-1][n-1];
}

int main(int argc, char const *argv[])
{
	int a[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
	cout<<MinCostPath(a, 3, 3);
	return 0;
}