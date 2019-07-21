#include<iostream>
using namespace std;

int partition(int* a, int l, int r) {
    int pivot = a[r],temp;
    int i=l-1,j=l;
    for(j=l;j<=r;j++) {
        if(a[j]<pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = pivot;
    a[r] = temp;
    return i;
}

void quicksort(int* a, int l, int r) {
    if(l<r) {
        int q = partition(a, l, r);
        quicksort(a, l, q);
        quicksort(a, q+1, r);
    }
}

/*int main() {
    int n,*a;
    cout<<"Enter n value :\n";
    cin>>n;
    a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a, 0, n-1);
    cout<<endl<<"Quick Sorted array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    delete []a;
    return 0;
}*/
