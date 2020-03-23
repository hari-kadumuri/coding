#include <bits/stdc++.h>
using namespace std;

int getNthUglyNumber(int n) {
	int i2 = 0, i3 = 0, i5 = 0, ugly[n];
	ugly[0] = 1;
	for(int i=1;i<n;i++) {
		int x = ugly[i2]*2;
		int y = ugly[i3]*3;
		int z = ugly[i5]*5;
		if(x<=y && x<=z)
			i2++;
		else if(y<=z)
			i3++;
		else
			i5++;
		ugly[i] = min(x, min(y, z));
		cout<<i2<<" "<<i3<<" "<<i5<<endl;
		if(ugly[i]==ugly[i-1])
			i--;
	}
	for(int i=0;i<n;i++) {
		cout<<ugly[i]<<" ";
	}
	cout<<endl;
	return ugly[n-1];
}

int main(int argc, char const *argv[])
{
	int n = 11;
	cout<<getNthUglyNumber(11)<<endl;
	return 0;
}