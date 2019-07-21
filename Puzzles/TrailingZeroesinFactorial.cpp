#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		int count = 0, fact = 5;
		while(n/fact>0) {
			count += n/fact;
			fact *= fact;
		}
		cout<<count<<endl;
	}
	return 0;
}