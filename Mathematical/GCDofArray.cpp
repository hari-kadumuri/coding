#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if(x==0)
		return y;
	else if(y==0)
		return x;
	else {
		while(x!=y && x && y) {
			if(x>y)
				x = x-y;
			else
				y = y-x;
		}
		return x;
	}
}

int main(int argc, char const *argv[])
{
	int T, *a;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		int n;cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
			a[i] = gcd(a[i-1], a[i]);
		cout<<a[n-1]<<endl;
	}
	return 0;
}