#include <bits/stdc++.h>
using namespace std;

int PossibleTilings(int n) {
	int a =2, b = 1, c = 1, d = 1;
	for(int i=5;i<=n;i++) {
		int temp = d;
		d = c;
		c = b;
		b = a;
		a = a+temp;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	cout<<PossibleTilings(n)<<endl;
	return 0;
}