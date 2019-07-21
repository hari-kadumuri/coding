#include <iostream>
using namespace std;

bool ifprime(int x) {
	if(x==1)
		return false;
	for(int i=2;i<x;i++)
		if(x%i==0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int n, T;
	cin>>T;
	while(T-- >0) {
		cin>>n;bool flag;
		while(n%2==0)
			n /= 2;
		for(int i=n;i>=3;i--) {
			if(n%i==0 && ifprime(i)) {
				cout<<i<<endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<2<<endl;
	}
	return 0;	
}