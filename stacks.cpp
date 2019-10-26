#include <iostream>
using namespace std;

int push(int* a, int top, int key) {
	top++;
	a[top] = key;
	return top;
}

int pop(int* a, int top) {
	top--;
	return top;
}

int isempty(int* a, int top) {
	if(top==-1)
		return 1;
	return 0;
}

int isfull(int* a, int top) {
	if(top==99)
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int	a[100], top = -1, n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int dummy;
		cin>>dummy;
		top = push(a, top, dummy);
	}
	
	while(!isempty(a, top)) {
		cout<<a[top]<<" ";
		top = pop(a, top);
	}
	cout<<"\n";
	return 0;
}