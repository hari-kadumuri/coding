#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, x, *a, count = 0; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cin>>x;
		for(int i=0;i<n;i++)
			if(a[i]<=x)
				count++;
		cout<<endl<<count<<endl;
		delete[] a;
	}
	return 0;
}