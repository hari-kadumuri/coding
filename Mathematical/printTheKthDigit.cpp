#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, T, k;
	cout<<"enter number of testcases:";
	cin>>T;
	while(T-- >0) {
		cin>>A>>B;
		cin>>k;
		long int prod = 1;
		long int x = pow(10, k);
		while(B-- >0) {
			prod *= A;
			prod %= x;
		}
		cout<<(prod-prod%(x/10))/(x/10)<<endl;
	}
	return 0;
}