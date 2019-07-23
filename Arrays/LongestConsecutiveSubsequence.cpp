#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findConsecutiveSubsequenceBySort(int* a, int n) { // runs in O(nlogn) time without using extra space
	sort(a, a+n);
	int len = 1, prevlen = 1;
	for(int i=1;i<n;i++) {
		if(a[i-1]+1 == a[i])
			len++;
		else if(prevlen<len || (i==n-1 && prevlen<len)){
			prevlen = len;
			len = 1;
		}
	}
	return prevlen;
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T-->0) {
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<"length of max consecutive subsequence = "<<findConsecutiveSubsequenceBySort(a, n)<<endl;
	}
	return 0;
}