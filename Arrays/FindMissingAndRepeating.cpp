#include <iostream>
using namespace std;

void findMissingAndRepeating(int* a, int n) {
	// finding repeated element
	int repeated;
	for(int i=0;i<n;i++)
		a[i]--;
	for(int i=0;i<n;i++) {
		int idx = a[i]%n;
		a[idx] += n;
		if(a[idx]/n>=2) {
			repeated = a[i]%n;
			break;
		}
	}
	int sum = 0;
	for(int i=0;i<n;i++) {
		a[i] %= n;
		a[i]++;
		sum += a[i];
	}
	repeated++;
	int missing = n*(n+1)/2 + repeated - sum;
	cout<<repeated<<" "<<missing<<endl;

}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n; cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		findMissingAndRepeating(a, n);
	}
	return 0;
}