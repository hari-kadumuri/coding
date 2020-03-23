#include <bits/stdc++.h>
using namespace std;

int MaximumSumIncreasingSubsequence(int a[], int n) {
	int opt[n] = {-1};
	opt[0] = a[0];
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			opt[i] = (a[j]<a[i]?max(opt[i], a[i]+opt[j]):opt[i]);
	int maxval = -1;
	for(int i=0;i<n;i++)
		maxval = max(maxval, opt[i]);
	return maxval;
}

int main(int argc, char const *argv[])
{
	int n;
	// cin>>n;
	n = 7;
	int a[n] = {1, 101, 2, 3, 100, 4, 5};
	cout<<MaximumSumIncreasingSubsequence(a, n)<<endl;
	return 0;
}