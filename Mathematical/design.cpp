#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n%2==0)
		cout<<"enter only odd number...!!"<<endl;
	int x = 0;
	while(x<1) {
		for (int i = 0; i < n/2; ++i)
		{
			for(int p = 0; p<n*x; p++)
				cout<<" ";
			if(i==0) {
				for (int j = 0; j < n; ++j)
					cout<<"*";
				cout<<endl;
				continue;
			}
			cout<<"*";
			for(int j=1;j<n-1;j++) {
				if(j==n/2-i+1)
					cout<<"*";
				else if(j==n/2+i-1)
					cout<<"*";
				else
					cout<<" ";
			}
			cout<<"*";

			cout<<endl;
		}
		for(int p = 0; p<x*n; p++)
				cout<<" ";
		cout<<"**";
		for(int i=2;i<n-2;i++)
			cout<<" ";
		cout<<"**";
		cout<<endl;
		for (int i = n/2+1; i < n; ++i)
		{
			for(int p = 0; p<x*n; p++)
				cout<<" ";
			if(i==n-1) {
				for (int j = 0; j < n; ++j)
					cout<<"*";
				cout<<endl;
				continue;
			}
			cout<<"*";
			for(int j=1;j<n-1;j++) {
				if(j==i-n/2+1)
					cout<<"*";
				else if(j==n-i-2+n/2)
					cout<<"*";
				else
					cout<<" ";
			}
			cout<<"*";
			cout<<endl;
		}
		x++;
	}
	return 0;
}