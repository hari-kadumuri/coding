#include<iostream>
using namespace std;

void countingsort(int* a, int n) {
    int Range = 40;
    int *b = new int[Range];
    for(int i=0;i<Range;i++)
        b[Range] = 0;
    for(int i=0;i<n;i++)
        b[a[i]]+=1;
    for(int i=1;i<Range;i++)
        b[i]+=b[i-1];
    int c[n];
    for(int i=0;i<n;i++) {
        c[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
    for(int i=0;i<n;i++)
        a[i] = c[i];
    delete []b;
    delete []c;
}

/*int main() {
    int n;
    cout<<"Enter n value :\n";
    cin>>n;
    int a[n];
    cout<<"Enter array values :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    countingsort(a,n);
    cout<<"\nCounting Sorted Array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    delete []a;
    return 0;
}
*/
