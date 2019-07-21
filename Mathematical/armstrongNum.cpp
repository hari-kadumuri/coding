#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		int x = n%10;
		int y = n%100;
		if(pow(x, 3) + pow((y-x)/10, 3) + pow((n-y)/100, 3) == n)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}