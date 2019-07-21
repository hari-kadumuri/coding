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
		int sum = 0;
		for(int i=0;i<n;i++)
			sum += a[i];
		cout<<endl<<sum;
		delete[] a;
	}
	return 0;
}