#include <bits/stdc++.h>
using namespace std;

long long int fact(int n) {
	int prod = 1;
	for(int i=0;i<n;i++)
		prod *= (i+1);
	return prod;
}

long long int combination(int n, int r) {
	return fact(n)/(fact(n-r)*fact(r));
}

int main() {
	int x = 24, y = 4;
	cout<<combination(x, y)<<endl;
	cout<<23*22*21<<endl;
	return 0;
}