#include <bits/stdc++.h>
using namespace std;

int MaxSumContiguosSubArray(int a[], int n) {
	int sum_end = 0, sum_back = 0, maxval = 0;
	for(int i=0;i<n;i++) {
		sum_end = max(a[i], a[i]+sum_back);
		sum_back = sum_end;
		maxval = max(maxval, sum_end);
	}
	return maxval;
}

int main(int argc, char const *argv[])
{
	int n = 8, a[n] = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<MaxSumContiguosSubArray(a, n)<<endl;
	return 0;
}