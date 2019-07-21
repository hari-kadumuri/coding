#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;cin>>T;
	while(T-- >0) {
		cin>>n;
		if(n==1)
			cout<<"NO";
		else if(n==2)
			cout<<"YES";
		else {
			int x = pow(n, 0.5);
			for(int i=2;i<=x;i++) {
				if(n%i==0) {
					cout<<"NO";
					break;
				}
				else if(i==x)
					cout<<"YES";
			}
		}
		cout<<endl;
	}
	return 0;
}