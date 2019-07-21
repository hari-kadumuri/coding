#include <iostream>
using namespace std;

int findmaxpath(int a[], int b[], int m, int n) {
	int countcommon = 0, c[(m<n?m:n)], i = 0, j = 0, k;
	while(i<m && j<n) {
		if(a[i]==b[j]) {
			c[countcommon++] = a[i];
			i++;
			j++;
		}
		else if(a[i]>b[j])
			j++;
		else
			i++;
	}

	int nodesizesA[countcommon+1], nodesizesB[countcommon+1];
	for(k=0;k<countcommon+1;k++)
		nodesizesA[k] = nodesizesB[k] = 0;
	
	for(i=m-1, k=countcommon-1;i>=0;i--) {
		if(a[i]>c[k] || k==-1)
			nodesizesA[k+1] += a[i];
		else if(a[i]==c[k])
			k--;
	}

	for(j=n-1, k=countcommon-1;j>=0;j--) {
		if(b[j]>c[k] || k==-1)
			nodesizesB[k+1] += b[j];
		else if(b[j]==c[k])
			k--;
	}

	int sumpath = (nodesizesB[0]>nodesizesA[0]?nodesizesB[0]:nodesizesA[0]);
	for(i=1;i<=countcommon;i++)
		sumpath += c[i-1] + (nodesizesB[i]>nodesizesA[i]?nodesizesB[i]:nodesizesA[i]);

	return sumpath;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int m, n;
		cin>>m>>n;
		int a[m], b[n];
		for(int i=0;i<m;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		cout<<findmaxpath(a, b, m, n)<<endl;
	}
	return 0;
}