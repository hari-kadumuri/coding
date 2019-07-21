#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		int i=1, prod = 1;
		while(i<=n)
			prod *= i++;
		cout<<prod<<endl;
	}
	return 0;
}