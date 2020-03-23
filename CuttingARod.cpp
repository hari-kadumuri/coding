#include <bits/stdc++.h>
using namespace std;

int MaxPrice(int prices[], int n) {
	int opt[n+1];
	opt[0] = 0;
	opt[1] = prices[1];
	for(int i=2;i<=n;i++) {
		int maxval = prices[i];
		for(int j=1;j<=i/2;j++)
			maxval = max(maxval, opt[j]+opt[i-j]);
		opt[i] = maxval;
	}
	return opt[n];
}

int main(int argc, char const *argv[])
{
	int n = 8;
	int prices[n+1] = {0, 3, 5, 8, 9, 10, 17, 17, 20};
	cout<<MaxPrice(prices, n)<<endl;
	return 0;
}