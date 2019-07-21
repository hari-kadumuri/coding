#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a; cin>>n;
		a = new int[n];
		bool *flag = new bool[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
			flag[i] = false;
		}
		int max = a[n-1];
		for(int i=n-1;i>-1;i--)
			if(max<=a[i]) {
				flag[i] = true;
				max = a[i];
			}
		cout<<endl;
		for(int i=0;i<n;i++)
			if(flag[i])
				cout<<a[i]<<" ";
		cout<<endl;
		delete[] a, flag;
	}
	return 0;
}