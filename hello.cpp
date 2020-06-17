#include <iostream>
using namespace std;

int add5(int a) {
	return a+5;
}

int main()
{
	cout<<"hello"<<endl;
	int a;
	cin>>a;
	cout<<add5(a)<<endl;
	return 0;
}