#include <iostream>
using namespace std;

int push(int* a, int back, int key) {
	back++;
	a[back] = key;
	return back;
}

int pop(int* a, int front) {
	front++;
	return front;
}

int isempty(int* a, int front, int back) {
	if(front>back)
		return 1;
	return 0;
}

int isfull(int* a, int back) {
	if(back==99)
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int	a[100], back = -1, front = 0, n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int dummy;
		cin>>dummy;
		back = push(a, back, dummy);
	}
	
	while(!isempty(a, front, back)) {
		cout<<a[front]<<" ";
		front = pop(a, front);
	}
	cout<<"\n";
	return 0;
}