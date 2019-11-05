#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void customSort1(int* a, int n) {
    for(int i=0;i<n;i++)
        if(a[i]%2==1)
            a[i] *= -1;
    sort(a, a+n);
    for(int i=0;i<n;i++)
        if(a[i]%2!=0)
            a[i] *= -1;
}

bool compare(int a, int b) {
	if(a%2==1 && b%2==1)
		return (a>=b?true:false);
	else if(a%2==0 && b%2==0)
		return (a<=b?true:false);
	else if(a%2==0)
		return false;
	return true;
}

void customSort2(int* a, int n) {
	sort(a, a+n, compare);
}

int main() {
	int T; cin>>T;
	while(T-- >0) {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    customSort1(a, n);
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	    customSort2(a, n);
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}