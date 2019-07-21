#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n; cin>>T;
	while(T-- >0) {
		cin>>n;
		int x = 0, y = 1;
		if(n==0)
			cout<<0<<0;
		else if(n==1)
			cout<<01;
		else if(n==2)
			cout<<0<<1;
		else {
			for(int i=0;i<n-2;i++) {
				y = (x+y)%100;
				x = (y-x)%100;
			}
			y = y+x; // 0 is treated as 0th fibanaaci number. So another computation is done.
			x = y%10; y = y/10;
			cout<<y<<x;
		}
		cout<<endl;
	}
	return 0;
}