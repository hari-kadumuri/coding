#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinComputations_REC(int* s, int l, int r) {
    if(l+1>=r)
        return 0;
    int min = INT_MAX;
    int a1, b1, c1;
    for(int i=l+1;i<r;i++) {
        int a = getMinComputations_REC(s, l, i), b =  getMinComputations_REC(s, i, r), c = s[l]*s[i]*s[r];
        int count = a+b+c;
        if(count<min) {
        	a1 = a; b1 = b; c1 = c;
            min = count;
        }
    }
    return min;
}

int DP_rec(int** min, int* s, int l, int r) {
	if(l+1>=r)
		return 0;
	int minval = INT_MAX;
	int a1, b1, c1;
	for(int i=l+1;i<r;i++) {
		if(min[l][i]==0)
			DP_rec(min, s, l, i);
		if(min[i][r]==0)
			DP_rec(min, s, i, r);
		int c = s[l]*s[i]*s[r];
        int count = min[l][i]+min[i][r]+c;
        if(count<minval)
            minval = count;
	}
	min[l][r] = minval;
	return min[l][r];
}

int getMinComputations_DP(int* s, int n) {
	int** min = new int*[n];
	for(int i=0;i<n;i++) {
		min[i] = new int[n];
		for(int j=0;j<n;j++) {
				min[i][j] = 0;
		}
	}
	int count = 0;
	DP_rec(min, s, 0, n-1);
	int x = min[0][n-1];
	for(int i=0;i<n;i++)
		delete[] min[i];
	delete min;
	return x;
}

void printArray(int* a, int n) {
	cout<<endl;
	for (int i = 0; i < n; ++i)
		cout<<i<<" -> "<<a[i]<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T-- >0) {
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
		printArray(a, n);
	    cout<<getMinComputations_REC(a, 0, n-1)<<endl;
	    cout<<getMinComputations_DP(a, n)<<endl;
	}
	return 0;
}