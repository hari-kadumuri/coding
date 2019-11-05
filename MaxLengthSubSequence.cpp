#include <bits/stdc++.h>
using namespace std;

int maxLengthSubsequence(int s, int n, int k) {
	int len = 0, a, b, asum, bsum;
	priority_queue aheap, bheap;
	if(n<1)
		return 0;
	if(s[0]>k) {
		a = 0;
		asum = 0;
	}
	else {
		a = 1;
		asum = s[0];
		aheap.push(s[0]);
	}
	b = 0;
	bsum = 0;
	for(int i=1;i<n;i++) {
		
	}
	return len;
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int a[n], k;
	cin>>k;
	cout<<maxLengthSubsequence(a, n, k)<<endl;
	return 0;
}