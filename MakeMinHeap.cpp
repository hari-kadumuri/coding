#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int* a, int i, int n) {
	int l = 2*i+1, r = 2*i+2;
	if(l>=n && r>=n)
		return;
	int min = l;
	if(r<n && a[l]>a[r])
		min = r;
	if(a[min]<a[i])
		swap(&a[min], &a[i]);
	minHeapify(a, min, n);
}

void MakeMinHeap(int* a, int n) {
	for(int i=n/2;i>=0;i--)
		minHeapify(a, i, n);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	MakeMinHeap(a, n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}