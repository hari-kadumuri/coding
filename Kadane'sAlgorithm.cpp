#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSum(int* a, int n) {
    if(n<=0) return 0;
    int lsum = a[0], gsum = a[0];
    for(int i=1;i<n;i++) {
    	lsum = max(lsum+a[i], a[i]);
    	gsum = max(gsum, lsum);
    }
    return gsum;
}

int main() {
	int T; cin>>T;
	while(T-- >0) {
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<maxSum(a, n)<<endl;
	}
	return 0;
}