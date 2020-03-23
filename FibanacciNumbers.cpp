#include <bits/stdc++.h>
using namespace std;

int getFibanacci(int n) {
	int a = 1, b = 0;
	if(n==0 || n==1) return n;
	cout<<"0 1 ";
	for(int i=2;i<=n;i++) {
		a += b;
		b = a-b;
		cout<<a<<" ";
	}
	cout<<endl;
	return a;
}

int main(int argc, char const *argv[])
{
	int n = 9;
	cout<<getFibanacci(n)<<endl;
	return 0;
}