#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, T;
	cout<<"enter number of test cases:";
	cin>>T;
	while(T-- > 0) {
		cin>>n;
		for(int i=n; i>0 ; i--) {
			for(int j=0;j<n;j++)
				for(int k=0;k<i;k++)
					cout<<n-j;
			cout<<endl;
		}
	}
	return 0;
}