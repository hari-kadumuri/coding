#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a;
		cin>>n;
		a = new int[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		for(int i=0;i<n;i++)
			if(i%2==0)
				cout<<a[i]<<" ";
		cout<<endl;
		delete[] a;
	}
	return 0;
}