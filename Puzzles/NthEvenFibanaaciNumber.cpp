#include <iostream>
using namespace std;

long long int findFib(int n) {
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	long long int x = 0, y = 1, fib;
	for(int i=3;i<=n;i++) {
		y = (y + x);
		x = (y - x);
	}
	return y;
}

int main(int argc, char const *argv[])
{
	int T, n; cin>>T;
	while(T-- >0) {
		cin>>n;
		n = 3*n+1;// nth even fibanaaci number(neglecting the 0) is (3*n+1)th fibanaaci number
		cout<<(n-1)/3<<"th Even Fibanaaci number is: "<<findFib(n)<<endl;
	}
	return 0;
}