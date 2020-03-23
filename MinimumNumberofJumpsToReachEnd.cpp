#include <bits/stdc++.h>
using namespace std;

int minJumps(int a[], int n) {
	if(n<=0) return 0;
	if(a[0]==0) return -1;
	int jump = 1, maxReach = a[0], steps = maxReach;
	for(int i=1;i<n;i++) {
		steps--;
		maxReach = max(maxReach, i+a[i]);
		if(i==n-1)
			break;
		if(steps==0) {
			jump++;
			if(i>=maxReach)
				return -1;
			steps = maxReach-i;
		}
	}
	return jump;
}

int main(int argc, char const *argv[])
{
	int n = 11, a[n] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	cout<<minJumps(a, n)<<endl;
	return 0;
}