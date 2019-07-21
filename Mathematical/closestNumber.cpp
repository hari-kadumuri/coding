#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, T, n;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>n>>m;
		m = (m<0)?-m:m;
		if(n%m==0)
			cout<<n;
		else {
			int x = n/m;
			if(n>=0) {
				if(m*(x+1)-n > n-m*x)
					cout<<m*x;
				else
					cout<<m*(x+1);
			}
			else {
				if(m*(x-1)-n < n-m*x)
					cout<<m*x;
				else
					cout<<m*(x+1);
			}
		}
		cout<<endl;
	}
	return 0;
}