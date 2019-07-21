#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, T, n;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>A>>B;
		cin>>n;
		cout<<A*pow(B/A, n-1);
	}
	cout<<endl;
	return 0;
}