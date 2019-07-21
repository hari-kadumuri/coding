// This code uses Moore's Voting Algorithm and runs in O(n) time complexity with O(n) space complexity
#include <iostream>
using namespace std;

int MaximumIndex(int* a, int n) {
	int i = 0, j = n-1;
	bool flag = true;
	while(j>=i) {
		if(a[i]<=a[j])
			return j-i;
		if(flag)
			j--;
		else
			i++;
		flag = !flag;
	}
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<MaximumIndex(a, n)<<endl;
		delete[] a;
	}
	return 0;
}