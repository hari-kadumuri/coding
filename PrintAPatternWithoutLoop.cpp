#include <iostream>
using namespace std;

void printPattern(int n) {
	if(n <= 0) {
		cout<<n<<" ";
		return;
	}
	cout<<n<<" ";
	printPattern(n-5);
	cout<<n<<" ";
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n; cin>>n;
		printPattern(n);
		cout<<endl;
	}
	return 0;
}