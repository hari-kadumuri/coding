
/*#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, d, *a; cin>>n>>d;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];				// This Code uses extra array and runs in O(n) time
		int* b = new int[n], x;
		for(int i=0;i<n;i++)
			b[(x = i-d)<0?x+n:x] = a[i];
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<endl;
		delete[] a, b;
	}
	return 0;
}*/

// The following Code runs without the use of extra array and runs in O(n)

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, d, *a; cin>>n>>d;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int x, steps = 0, temp, val = a[0], i = 0;
		while(steps++<n) {
			x = i-d<0?i-d+n:i-d;
			temp = a[x];
			a[x] = val;
			val = temp;
			i = x;
		}
		cout<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		delete[] a;
	}
	return 0;
}