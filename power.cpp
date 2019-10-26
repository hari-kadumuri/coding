#include <iostream>
using namespace std;

int getNodePower(int x) {
	bool flag[x+1];
	for(int i=0;i<x+1;i++)
		flag[i] = false;
	int i = 2;
	while(i<x) {
		if(flag[i]==true)
			i++;
		else {
			int s = i*i;
			for(int j = 0; s+j < x+1; j += i)
				flag[s+j] = true;
			i++;
		}
	}
	int prod = 1;
	for(int i=2;i<x+1;i++)
		if(flag[i]==false && x%i==0)
			prod *= i;
	return prod;
}

int main(int argc, char const *argv[])
{
	cout<<getNodePower(10);
	return 0;
}