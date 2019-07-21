#include<iostream>
using namespace std;

void Merge(int* a, int left, int mid, int right) {
    int i, k, i1, j, i2,c[right-left+1];
    i = k = i1 = left;
    int j1 = mid;
    j = i2 = mid+1;
    int j2 = right;
    while(i<=j1 && j<=j2) {
        if(a[i]>a[j])
            c[k++] = a[j++];
        else
            c[k++] = a[i++];
    }
    while(i<=j1)
        c[k++] = a[i++];
    while(j<=j2)
        c[k++] = a[j++];
    for(i=left;i<=right;i++)
        a[i] = c[i];
}

void mergesort(int* a, int left, int right) {
    int mid = (left+right)/2;
    if(right>left) {
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        Merge(a,left, mid, right);
    }
    else {
        int temp;
        if(a[right]>a[left]) {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
}


int main() {
    int n;
    cout<<"Enter n :\n";
    cin>>n;
    int a[n];
    int i=0;
    cout<<"Enter array values :\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    cout<<endl<<"Merged Sorted array :\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    delete []a;
    return 0;
}
