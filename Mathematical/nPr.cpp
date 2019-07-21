#include <iostream>
using namespace std;

int factorial(int n) {
	int i=1, prod = 1;
	while(i<=n)
		prod *= i++;
	return prod;
}

int main(int argc, char const *argv[])
{
	int T, n, r;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0 && cin>>n>>r)
		cout<<factorial(n)/factorial(n-r)<<endl;
	return 0;
}