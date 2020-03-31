#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	int p = 1, i = 0;
	while(++i && i<=n)
		p *= i;
	return p;
}

int combinations(int n, int r) {
	return fact(n)/fact(r)/fact(n-r);
}

int PossibleSeqs(int n) {
	return combinations(2*n, n);
}

int main(int argc, char const *argv[])
{
	int n = 2;
	cout<<PossibleSeqs(n)<<endl;
	cout<<fact(4)<<endl;
	return 0;
}
