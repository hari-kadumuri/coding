#include <iostream>
#include <cstdlib>
using namespace std;

int generateperfectoddnumber() {
	int product = 1;
	srand(time(NULL));
	int maxiteration = rand()%10;
	cout << "maxiteration = "<< maxiteration<<endl;
	for(int i=0;i<maxiteration;i++)
		product = (2*product+1);
	return product;
}

int main(int argc, char const *argv[])
{
	//int n = generateperfectoddnumber();		// the recursive definition of perfect odd number: if n is perfect odd then n/2 is also perfect odd, 1 is perfect odd
	int n = 15;
	cout<<"generated perfect random number = "<<n<<endl;
	int i=0;
	int fact = 0;
	while(i<=n/2) {
		if(i==fact) {
			/*cout<<"*";
			for(int j=1;j<i;j++)
				cout<<" ";
			for(int j=i;j<n-2*i;j++)
				cout<<"*";
			for(int j=0;j<i-1;j++)
				cout<<" ";
			cout<<"*";*/
			for(int j=0;j<n;j++) {
				if(j==0)
					cout<<" ";
				else
					cout<<"*";
			}
			fact = (fact + (int)(n/2))/2;
		}
		else {
			for(int j=0;j<n;j++) {
				if(j==(int)n/2-i || j==(int)n/2+i)
					cout<<"*";
				else
					cout<<" ";
			}
		}
		cout<<endl;
		i++;
	}
	/*else {
		}*/
	return 0;
}