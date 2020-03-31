#include <bits/stdc++.h>
using namespace std;

int PossibleWays(int n) {
	int count[n+1] = {0};
	count[0] = 1;
	for(int i=3;i<=n;i++)
		count[i] += count[i-3];
	for(int i=5;i<=n;i++)
		count[i] += count[i-5];
	for(int i=10;i<=n;i++)
		count[i] += count[i-10];
	return count[n];
}

int main(int argc, char const *argv[])
{
	int n = 13;
	cout<<PossibleWays(n)<<endl;
	return 0;
}