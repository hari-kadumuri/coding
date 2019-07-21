#include <iostream>
#include <cstdlib>
#include <malloc.h>
using namespace std;

int generateperfectoddnumber() {
	int product = 3;
	srand(time(NULL));
	int maxiteration = rand()%10;
	for(int i=0;i<maxiteration;i++) {
		product = (2*product-1);
		if(product>200) {
			product = (1+product)/2;
			break;
		}
	}
	return product;
}

void printarray(char** x, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cout<<x[i][j];
		cout<<endl;
	}
}

void fillarray(char** x, int n, int offset, int size) {
	if(size==3) {
		x[offset][offset] = x[offset][offset+1] = x[offset][offset+2] = '*';
		x[offset+1][offset] = x[offset+1][offset+2] = '*';
		x[offset+2][offset] = x[offset+2][offset+1] = x[offset+2][offset+2] = '*';
		return;
	}
	for(int i=0;i<size;i++)
		x[offset][offset+i] = x[offset+size-1][offset+i] = '*';
	for(int i=1;i<=size/2;i++)
		x[offset+i][offset+size/2-i] = x[offset+i][size/2+i+offset] = x[offset+i][size-1+offset] = x[offset+i][offset] = '*';
	for(int i=size/2+1;i<size-1;i++)
		x[offset+i][offset+i-size/2] = x[offset+i][size-i+size/2+offset-1] = x[offset+i][size-1+offset] = x[offset+i][offset] = '*';
	offset = offset+n/2;
	fillarray(x, n, offset/2, (size+1)/2);
}

int main(int argc, char const *argv[])
{
	int n = generateperfectoddnumber();		// the recursive definition of perfect odd number: if n is perfect odd then (n+1)/2 is also perfect odd, 3 is perfect odd
	cout<<"generated perfect random number = "<<n<<endl;
	char** x = (char**)malloc(n*sizeof(char*));
	for (int i = 0; i < n; ++i)
		x[i] = (char*)malloc(n*sizeof(char));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			x[i][j] = ' ';
	fillarray(x, n, 0, n);
	cout<<endl<<"Design :\n";
	printarray(x, n);
	for(int i=0;i<n;i++)
		free(x[i]);
	free(x);
	return 0;
}