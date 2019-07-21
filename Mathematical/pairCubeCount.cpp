#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;int range;
		for(range=1;range<n;range++)
			if(range*range*range>n)
				break;
		range--;
		cout<<"range = "<<range<<endl;
		int i = 1, j = range, count = 0;
		while(i<=j) {
			int sum = i*i*i + j*j*j;
			if(sum == n) {
				count++;
				i++;j--;
			}
			else if(sum > n)
				j--;
			else
				i++;
		}
		count *= 2;
		if(range*range*range == n)
			count++;
		cout<<count<<endl;
	}
	return 0;
}