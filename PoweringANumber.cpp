#include  <iostream>
using namespace std;

int getPower(int n, int x) {
	if(x==0)
		return 1;
	int p = getPower(n, x/2);
	return (x%2==0?p*p:p*p*n);
}

int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n>>x;
	cout<<getPower(n, x)<<endl;
	return 0;
}