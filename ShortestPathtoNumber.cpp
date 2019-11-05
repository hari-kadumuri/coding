#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
	int rev = 0;
	while(n>0) {
		rev = rev*10 + n%10;
		n = n/10;
	}
	return rev;
}

int findMinSteps(int n) {
	int opt[n+1];
	opt[0] = 0;
	for(int i=1;i<=n;i++) {
		int x = reverse(n);
		opt[i] = min(1+opt[i-1], (x<n?opt[x]:n+1));
	}
	return opt[n];
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	cout<<findMinSteps(n)<<endl;
	return 0;
}