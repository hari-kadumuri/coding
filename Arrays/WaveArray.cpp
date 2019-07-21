// This code uses Moore's Voting Algorithm and runs in O(n) time complexity with O(n) space complexity
#include <iostream>
using namespace std;

void reArrangeintoWave(int* a, int n) {
	for(int i=0;i<n-n%2;i+=2) {
		int tmp = a[i];
		a[i] = a[i+1];
		a[i+1] = tmp;
	}
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		reArrangeintoWave(a, n);
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		delete[] a;
	}
	return 0;
}