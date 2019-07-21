#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n;
		cin>>n;
		int a[n];
		long long int product = 1;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			product *= a[i];
		}
		cout<<endl;
		for(int i=0;i<n;i++) {
			a[i] = product/a[i];
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}