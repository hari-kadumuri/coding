#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	// only squares of prime numbers have only 3 factors. So solution is to print the squares of prime numbers less than or equal to n
	int T, n;cin>>T;
	while(T-- >0) {
		cin>>n;
		// using of Sieve of Eratosthenes to find prime numbers less than or equal to n. Runs in O(n) time
		bool* flag = new bool[n+1];
		for(int i=0;i<n+1;i++)
			flag[i] = false;
		int i = 2;
		while(i<n) {
			if(flag[i]==true)
				i++;
			else {
				int s = i*i;
				for(int j = 0; s+j < n+1; j += i)
					flag[s+j] = true;
				i++;
			}
		}
		// now flag[i] is false is 'i' is prime
		int count = 0;
		for(int i=2;i<n+1;i++)
			if(flag[i]==false && i*i<=n)
				count++;
		cout<<count<<endl;
		delete[] flag;
	}
	return 0;
}