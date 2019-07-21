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
		int temp;
		for(int i=0;i<n/2;i++) {
			temp = a[i];
			a[i] = a[n-1-i];
			a[n-i-1] = temp;
		}
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		delete[] a;
	}
	return 0;
}