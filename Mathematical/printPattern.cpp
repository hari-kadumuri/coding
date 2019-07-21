#include <iostream>
using namespace std;

void printPattern(int n, int val, bool ifdecrease) {
	cout<<val<<" ";
	if(ifdecrease==true) {
		val -= 5;
		if(val>0)
			printPattern(n, val, true);
		else
			printPattern(n, val, false);
	}
	else{
		if(val==n)
			return;
		else {
			val += 5;
			printPattern(n, val, false);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, T;
	cout<<"enter number of testcases:";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		printPattern(n, n, true);
	}
	cout<<endl;
	return 0;
}