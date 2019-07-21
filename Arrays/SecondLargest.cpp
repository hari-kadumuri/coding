#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int max = a[0], secondmax = -99999999;
		for(int i=0;i<n;i++) {
			if(max<a[i]) {
				secondmax = max;
				max = a[i];
			}
			else if(a[i] >secondmax && max!=a[i])
				secondmax = a[i];
		}
		cout<<endl<<secondmax;
		delete[] a;
	}
	return 0;
}