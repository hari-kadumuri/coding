#include <iostream>
using namespace std;

bool search(int* a, int x, int n) {
	for (int i = 0; i < n; ++i)
		if(a[i]==x)
			return true;
	return false;
}

bool insert(int* a, int x, int idx, int n) {
	if(idx<n) {
		a[idx] = x;
		return true;
	}
	return false;
}

bool del(int* a, int x, int n) {
	int i;
	for (i = 0; i < n; ++i)
		if(a[i]==x)
			break;
	if(i==n)
		return false;
	for(int j=i;j<n-1;j++)
		a[j] = a[j+1];
	return true;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n; cin>>n;
		int* a = new int[n];
		int x, y, yi, z;
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		cin>>x>>y>>yi>>z;
		if(search(a, x, n)==false)
			cout<<0<<" ";
		else
			cout<<1<<" ";
		if(insert(a, y, yi, n)==false)
			cout<<0<<" ";
		else
			cout<<1<<" ";
		if(del(a, z, n)==false)
			cout<<0<<endl;
		else
			cout<<1<<endl;
		delete[] a;
	}
	return 0;
}