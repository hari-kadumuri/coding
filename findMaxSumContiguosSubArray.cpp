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

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	cout<<"enter array:\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"sum of max sum contigous array = "<<maxSumContiguosSubArray(a, n)<<endl;
	return 0;
}