#include <bits/stdc++.h>
using namespace std;

int maxSumContiguosSubArray(int a[], int n) {
	int sumtillnow = a[0], maxsum = a[0];
	for(int i=1;i<n;i++) {
		sumtillnow = max(sumtillnow+a[i], a[i]);
		maxsum = max(maxsum, sumtillnow);
	}
	return maxsum;
}

int maxSumSubArraayInAMatrix(int a[][100], int m, int n) {
	int sum[m][n];
	for(int i=0;i<m;i++) {
		sum[i][0] = a[i][0];
		for(int j=1;j<n;j++)
			sum[i][j] = a[i][j]+sum[i][j-1];
	}
	int maxsum = a[0][0];
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			int temp[m];
			for(int k=0;k<m;k++)
				temp[k] = sum[k][j] - (i>0?sum[k][i-1]:0);
			maxsum = max(maxsum, maxSumContiguosSubArray(temp, m));
		}
	}
	return maxsum;
}

int main(int argc, char const *argv[]) {
	int m, n;
	cin>>m>>n;
	int a[m][100];
	cout<<"enter matrix: (row wise)"<<endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	cout<<"output = "<<maxSumSubArraayInAMatrix(a, m, n)<<endl;
	return 0;
}