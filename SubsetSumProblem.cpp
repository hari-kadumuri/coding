#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int a[], int n, int sum) {
	bool opt[sum+1][n];
	for(int i=0;i<=sum;i++) {
		for(int j=0;j<n;j++) {
			if(i==0)
				opt[i][j] = true;
			else if(j==0)
				opt[i][j] = (i==a[0]?true:false);
			else
				opt[i][j] = (opt[i][j-1] || (i>=a[j]?opt[i-a[j]][j]:false));
		}
	}
	return opt[sum][n-1];
}

int main(int argc, char const *argv[])
{
	int n = 6, a[n] = {3, 34, 4, 12, 5, 2}, sum = 9;
	cout<<isSubsetSum(a, n, sum)<<endl;
	return 0;
}