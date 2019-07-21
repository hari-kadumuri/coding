// This Code runs in O(n^2)+O(nlogn)+O(1000) time with O(n)+O(1000) space complexity
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;j = 0;k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
            arr[k++] = L[i++]; 
        else
            arr[k++] = R[j++]; 
    } 
    while (i < n1) 
        arr[k++] = L[i++]; 
    while (j < n2) 
        arr[k++] = R[j++]; 
} 

void mergesort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
        mergesort(arr, l, m); 
        mergesort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a, *b = new int[1001], count = 0, x, y; cin>>n;
		a = new int[n];
		for(int i=0;i<1001;i++)
			b[i] = 0;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			b[a[i]]++;
		}
		mergesort(a, 0, n-1);
		for(int i=1;i<1001;i++)
			b[i] += b[i-1];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				count += b[a[i]+a[j]-1] - b[a[j]];
		cout<<count<<endl;
		delete[] a;
	}
	return 0;
}