#include <iostream>
using namespace std;

int DPFibanaacci(int n) {
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	int a = 0, b = 1, c;
	for(int i=3;i<=n;i++) {
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int recursivefindFibanaacci(int n) {
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	return recursivefindFibanaacci(n-1)+recursivefindFibanaacci(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<recursivefindFibanaacci(n)<<endl;
	cout<<DPFibanaacci(n)<<endl;
	return 0;
}