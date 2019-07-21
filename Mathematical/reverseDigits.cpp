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
		int tmp;
		fact = 1;
		for(int i=0;i<digits/2;i++) {
			tmp = a[i];
			a[i] = a[digits-i-1];
			a[digits-i-1] = tmp;
		}
		int reversenumber = 0;
		for(int i=0;i<digits;i++, fact *= 10)
			reversenumber += a[i]*fact;
		cout<<reversenumber<<endl;
		delete[] a;
	}
	return 0;
}

/***************************** Try it without using memory *******************************/