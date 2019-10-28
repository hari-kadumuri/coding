#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Merge(vector<int> &a, int l1, int r1, int l2, int r2) {
	int temp[r2-l1+1], k = 0, i, j;
	for(i=l1, j=l2; i<=r1 && j<=r2; k++) {
		if(a[i]<a[j])
			temp[k] = a[i++];
		else
			temp[k] = a[j++];
	}
	while(i<=r1)
		temp[k++] = a[i++];
	while(j<=r2)
		temp[k++] = a[j++];
	for(i=l1;i<=r2;i++)
		a[i] = temp[i-l1];
}

void MergeSort(vector<int> &a, int l, int r) {
	if(l<r) {
		int mid = (l+r)/2;
		MergeSort(a, l, mid);
		MergeSort(a, mid+1, r);
		Merge(a, l, mid, mid+1, r);
	}
}

int binarySearch(vector<int> &a, int l, int r, int key) {
	if(l==r)
		return (a[l]==key?l:-1);
	int mid = (l+r)/2;
	if(key<=a[mid])
		return binarySearch(a, l, mid, key);
	else
		return binarySearch(a, mid+1, r, key);
}

int partition(vector<int> &a, int l, int r) {
	int pivot = a[r];
	int i = l-1;
	for(int j=l;j<r;j++) {
		if(a[j]<=pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[r]);
	return i+1;
}

void QuickSort(vector<int> &a, int l, int r) {
	if(l<r) {
		int p = partition(a, l, r);
		QuickSort(a, l, p-1);
		QuickSort(a, p+1, r);
	}
}

void printArray(vector<int> &a) {
	cout<<endl;
	int n = a.size();
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	cout<<endl;
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	MergeSort(a, 0, n-1);
	printArray(a);
	int key;
	cout<<"enter the value to be searched:";
	cin>>key;
	cout<<binarySearch(a, 0, n-1, key)<<endl;
	QuickSort(a, 0, n-1);
	printArray(a);
	return 0;
}