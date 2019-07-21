#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, x, y;
	cin>>T;
	while(T-- >0) {
		cin>>x>>y;
		if(x==1 && y!=1)
			cout<<0;
		else {
			while(1) {
				y /= x;
				if(y==x) {
					cout<<1;
					break;
				}
				else if(y<x) {
					cout<<0;
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}