#include <iostream>
#include <cmath>
using namespace std;
// this code runs in O(n) time.
/*int main(int argc, char const *argv[])
{
	int T, n;cin>>T;
	while(T-- >0) {
		cin>>n;
		int sum = 0, i = 1;
		while(sum<n) {
			sum += i++;
			if(sum==n) {
				cout<<1<<endl;
				break;
			}
			else if(sum>n) {
				cout<<0<<endl;
				break;
			}
		}
	}
	return 0;
}*/

// the following code runs in O(1) time. if n is triangular number then sqrt(8n+1) should be an integer.
// this condition can be obtained by equating n to sum of first x natural numbers and using the argument that x is an positive integer.

int main(int argc, char const *argv[])
{
	int T, n; cin>>T;
	while(T-- >0) {
		cin>>n;double p;
		if((p=pow(8*n+1, 0.5))==(int)p)
			cout<<1;
		else
			cout<<0;
		cout<<endl;
	}
	return 0;
}