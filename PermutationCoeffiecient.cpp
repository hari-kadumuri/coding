#include <bits/stdc++.h>
using namespace std;

int getnPr(int n, int r) {
	int opt[r+1];
	opt[0] = 1;
	for(int i=1;i<=r;i++)
		opt[i] = (n-i+1)*opt[i-1];
	return opt[r];
}

int main(int argc, char const *argv[])
{
	int n = 10, r = 3;
	cout<<getnPr(n, r)<<endl;
	return 0;
}