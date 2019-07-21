#include <iostream>
#include <cmath> 
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n, sum = 1;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		float x = pow(n, 0.5);
		cout<<x<<endl;
		for(int i=2;i<x;i++)
			if(n%i==0)
				sum += i + n/i;
			if(x==(int)x)
				sum += x;
		cout<<((sum==n)?1:0)<<endl;
	}
	return 0;
}