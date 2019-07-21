#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, x, y;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>x>>y;
		if(x==0)
			cout<<y;
		else if(y==0)
			cout<<x;
		else {
			while(x!=y && x && y) {
				if(x>y)
					x = x-y;
				else
					y = y-x;
			}
			cout<<x;
		}
		cout<<endl;
	}
	return 0;
}