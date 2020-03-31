#include <bits/stdc++.h>
using namespace std;

int PossibleTilings(int n) {
	int a =2, b = 1;
	for(int i=3;i<=n;i++) {
		a = a+b;
		b = a-b;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int n = 4;
	cout<<PossibleTilings(n)<<endl;
	return 0;
}
