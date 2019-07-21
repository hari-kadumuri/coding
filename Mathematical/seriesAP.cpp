#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, T, n;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-- >0) {
		cin>>A>>B;
		cin>>n;
		cout<<(n-1)*B-(n-2)*A;
	}
	cout<<endl;
	return 0;
}