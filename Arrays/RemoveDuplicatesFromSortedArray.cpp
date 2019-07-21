#include <iostream>
using namespace std;
// This Code runs in O(n) time with O(1) space complexity
int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a, x = 0; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
			if(a[i]-a[i-1])
				a[++x] = a[i];
		// Printing modified array
		cout<<endl;
		for(int i=0;i<=x;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		delete[] a;
	}
	return 0;
}