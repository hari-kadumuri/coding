#include <iostream>
using namespace std;
#include <cmath>

int main(int argc, char const *argv[])
{
	int T, n;
	long long int m;
	cin>>T;
	while(T-- >0) {
		cin>>n>>m;
		for(int i=1;i<m/n;i++) {
			if(pow(i, n) == m)
				cout<<i<<endl;
			else if(i==m/n-1)
				cout<<-1<<endl;
		}
	}
	return 0;
}