#include <iostream>
using namespace std;

long long int countBst(int n) {
	long long int a[n+1];
	a[0] = a[1] = 1;
	for(int i=2;i<n+1;i++) {
		a[i] = 0;
		for(int j=1;j<=i;j++)
			a[i] += a[j-1]*a[i-j];
	}
	return a[n];
}

int main(int argc, char const *argv[])
{
	int n = 10;
	cout<<countBst(n)<<endl;
	return 0;
}