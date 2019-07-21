// This code uses Moore's Voting Algorithm and runs in O(n) time complexity with O(n) space complexity
#include <iostream>
using namespace std;

int findmajority(int* a, int n) {
	int count = 1, majority_idx = 0;
	for(int i=1;i<n;i++) {
		if(a[majority_idx]==a[i])
			count++;
		else
			count--;
		if(count==0 && (count = 1))
			majority_idx = i;
	}

	// The Moore's Voting algorithm returns only the element that is repeated the most.
	// Inorder to make sure that there is a majority element, the following check is done
	count = 0;
	for(int i=0;i<n;i++)
		if(a[majority_idx] == a[i])
			count++;
	if(count>n/2)
		return a[majority_idx];
	return -1;	
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<findmajority(a, n)<<endl;
		delete[] a;
	}
	return 0;
}