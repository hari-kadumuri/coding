#include <iostream>
using namespace std;

int findLCM(int x, int y) {
	int m = x, n = y;
		if(x==0)
			return y;
		else if(y==0)
			return x;
		else {
			while(x!=y && x && y) {
				if(x>y)
					x = x-y;
				else
					y = y-x;
			}
			return m*n/x;
		}
}

int main(int argc, char const *argv[])
{
	int T, num1, den1, num2, den2;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>num1>>den1>>num2>>den2;
		int denx = findLCM(den1, den2);
		int numx = num1*(denx/den1) + num2*(denx/den2);
		cout<<numx<<'/'<<denx;
		cout<<endl;
	}
	return 0;
}