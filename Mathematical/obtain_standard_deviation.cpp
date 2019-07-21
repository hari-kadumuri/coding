#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{E
	int N, d;
	cin>>N>>d;
	for(int i=0;i<N-1;i++)
		cout<<0<<"\t";
	cout<<(float)N*d/(float)sqrt(N-1)<<endl;
	return 0;
}