#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, T;
	cout<<"enter test cases: ";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		for(int i=0;i<10;i++)
			cout<<n*i+n<<" ";
		cout<<endl;
	}
	return 0;
}