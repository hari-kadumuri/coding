#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int DP(vector<int> &a, int l, int r) {
	if(l>r)
		return 0;
	if(l==r)
		return a[l];
	int opt1 = a[l], opt2 = 0;
	for(int i=l+1;i<=r;i++) {
		int temp = opt1;
		opt1 = a[i]+opt2;
		opt2 = max(temp, opt2);
	}
	return max(opt1, opt2);
}

int getYield(vector<int> &a) {
	return max(a[0]+DP(a, 2, a.size()-2), DP(a, 1, a.size()-1));
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	cout<<getYield(a)<<endl;
	return 0;
}