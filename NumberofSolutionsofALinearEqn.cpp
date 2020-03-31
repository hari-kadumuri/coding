#include <bits/stdc++.h>
using namespace std;

// runs in rhs*n time
int PossibleSolutions2(int a[], int n, int rhs) {
	int sol[rhs+1] = {0};
	sol[0] = 1;
	for(int i=0;i<n;i++)
		for(int j=a[i];j<=rhs;j++)
			sol[j] += sol[j-a[i]];
	return sol[rhs];
}

// runs in rhs*rhs*n time in worst case
int PossibleSolutions1(int a[], int n, int rhs) {
	int sol[n+1][rhs+1];
	for(int i=1;i<n+1;i++) {
		for(int j=0;j<=rhs;j++) {
			if(i==1) sol[i][j] = (j%a[0]==0?1:0);
			else if(j==0) sol[i][j] = 1;
			else {
				sol[i][j] = 0;
				for(int k=0;k<=rhs;k=k+a[i-1])
					sol[i][j] += (j>=k?sol[i-1][j-k]:0);
			}
		}
	}
	for(int i=1;i<n+1;i++) {
		for(int j=0;j<=rhs;j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
	return sol[n][rhs];
}

int main(int argc, char const *argv[])
{
	int n = 3, a[n] = {2, 2, 3}, rhs = 4;
	cout<<PossibleSolutions1(a, n, rhs)<<endl;
	cout<<PossibleSolutions2(a, n, rhs)<<endl;
	return 0;
}