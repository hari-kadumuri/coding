#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		int i = 1;
		while(i*i < n && i++);
		cout<<i-1<<endl;
	}
	return 0;
}