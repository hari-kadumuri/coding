#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int* compare(int* a, int* b, int m, int n) {
	int flag = 0;
	sort(a, a+m);
	sort(b, b+n);
	if(m<n) {
		int* tmp = a;
		a = b;
		b = tmp;
		int x = m;
		m = n;
		n = x;
		flag = 1;
	}
	int i = 0, j = 0;
	int* c = new int[n+1];
	while(j<n) {
		while(i<m && a[i]<b[j])
			i++;
		if(i==m) {
			c[n] = 0;
			return c;
		}

		c[j++] = i++;
	}
	c[n] = (flag==0?1:-1);
	return c;
}

int main(int argc, char const *argv[])
{
	int m, n;
	cin>>m>>n;
	int a[m], b[n];
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	int* c = compare(a, b, m, n);
	cout<<"result: "<<c[(m<n?m:n)]<<endl;
	cout<<"Mappings are:\n";
	if(m>=n && c[n] != 0) {
		for(int i=0;i<n;i++)
			cout<<b[i]<<" -> "<<a[c[i]]<<"\n";
	}
	else if(c[m] != 0){
		for(int i=0;i<m;i++)
			cout<<a[i]<<" -> "<<b[c[i]]<<"\n";
	}
	delete[] c;
	return 0;
}