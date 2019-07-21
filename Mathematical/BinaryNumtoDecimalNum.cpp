#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, x;
	cin>>T;
	while(T-- >0) {
		int num = 0, fact = 1;
		cin>>x;
		while(x>0) {
			num += (x%10)?fact:0;
			fact *= 2;
			x /= 10;
		}
		cout<<num<<endl;
	}
	return 0;
}