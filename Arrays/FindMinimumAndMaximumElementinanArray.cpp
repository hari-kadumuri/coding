#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a;
		cin>>n;
		a = new int[n];
		int min = 99999999, max = -99999999;
		for (int i = 0; i < n; ++i) {
			cin>>a[i];
			if(min>a[i])
				min = a[i];
			if(max<a[i])
				max = a[i];
		}
		cout<<endl<<min<<" "<<max;
		delete[] a;
	}
	return 0;
}