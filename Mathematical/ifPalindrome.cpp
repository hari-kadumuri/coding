/*#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, T;
	cout<<"enter number of testcases:";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		if(n==0)
			cout<<"YES";
		else {
			int digits = 0, fact = 1;
			while(fact<n) {
				digits++;
				fact *= 10;
			}
			fact = pow(10, digits);
			int i;
			for(i=1;i<pow(10, digits/2);i = i*10) {
				int x = n%fact;
				fact /= 10;
				int y = n%fact;
				int a = n%i;
				int b = n%(i/10);
				int c = pow(10, n-1-2*i);
				if(x-y != (a-b)*c)
					break;
				fact /= 10;
			}
			if(i==digits/2)
				cout<<"YES";
			else
				cout<<"NO";
		}
	}
	cout<<endl;
	return 0;
}

***************** RECTIFY THE ABOVE CODE. IT HAS SOME ERROR. THE FOLLOWING CODE WORKS FINE BUT USES MEMORY*****************/

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, T;
	cout<<"enter number of testcases:";
	cin>>T;
	while(T-- >0) {
		cin>>n;
		int digits = 0, fact = 1;
		while(fact<n) {
			digits++;
			fact *= 10;
		}
		int* a = new int[digits];
		fact = 10;
		for(int i=0;i<digits;i++, fact *= 10)
			a[i] = (n%fact - n%(fact/10))/(fact/10);
		int flag = 1;
		for(int i=0;i<digits/2;i++)
			if(a[i] != a[digits-1-i])
				flag = 0;
		if(flag)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
		delete[] a;
	}
	return 0;
}