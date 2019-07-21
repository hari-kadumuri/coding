#include<iostream>
using namespace std;
#include<time.h>

void maxheapify(int a[], int i, int n) {
    int l = 2*i+1, r = l+1,temp;
    if(r<n) {
        if(a[l]>a[i]&&a[l]>a[r]) {
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;
            maxheapify(a, l, n);
        }
        else if(a[r]>a[i]) {
            temp = a[i];
            a[i] = a[r];
            a[r] = temp;
            maxheapify(a, r, n);
        }
    }
    else if(l<n) {
        if(a[l]>a[i]) {
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;

        }
    }
}

void makemaxheap(int* a, int n) {
    for(int i=n/2;i>=0;i--)
        maxheapify(a,i,n);
}

void heapsort(int* a, int start, int endidx) {
    int n = endidx-start+1, temp;
    int* c = new int[n];
    for(int i=0;i<n;i++) {
        makemaxheap(a,n-i);
        c[i] = a[0];
        temp = a[n-i-1];
        a[n-i-1] = a[0];
        a[0] = temp;
    }
}

void insertkey(int *a, int x, int n) {
        a[n] = x;
        makemaxheap(a,n+1);
}

/*int main() {
    int n,*a;
    cout<<"Enter n value :\n";
    cin>>n;
    cout<<"Enter Array elements :\n";
    a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    clock_t c1,c2;
    c1 = clock();
    makemaxheap(a,n);
    c2 = clock();
    cout<<"Heaped Array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<"\nHeaping Process is completed in :\t"<<(double)(c2-c1)/(double)CLOCKS_PER_SEC;
    c1 = clock();
    heapsort(a,0,n-1);
    c2 = clock();
    cout<<"\nHeap Sorted Array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<"\nHeapSorting Process is completed in :\t"<<(double)(c2-c1)/(double)CLOCKS_PER_SEC;
    insertkey(a,5,n);
    cout<<"\nArray after insertion:\t";
    for(int i=0;i<n+1;i++)
        cout<<a[i]<<"\t";
    a[n+5] = 7;
    delete []a;
    return 0;
}*/
