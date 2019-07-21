#include<iostream>
#include<math.h>
using namespace std;

int getdigit(int key, int idx) {
    key= key%(int)pow(10, idx) - key%(int)pow(10,idx-1);
    while(key>=10)
        key/=10;
    return key;
}

void modifiedcountingsort(int* a, int n, int idx) {
    int Range = 10;
    int *b = new int[Range];
    for(int i=0;i<Range;i++)
        b[Range] = 0;
    for(int i=0;i<n;i++)
        b[getdigit(a[i], idx)]+=1;
    for(int i=1;i<Range;i++)
        b[i]+=b[i-1];
    int c[n];
    for(int i=0;i<n;i++) {
        c[b[getdigit(a[i], idx)]-1] = a[i];
        b[getdigit(a[i], idx)]--;
    }
    for(int i=0;i<n;i++)
        a[i] = c[i];
    delete []b;
    delete []c;
}

void radixsort(int* a, int n, int d) {
    for(int i=0;i<d;i++)
        modifiedcountingsort(a, n, i+1);
}

/*int main() {
    int n;
    cout<<"Enter n value :\n";
    cin>>n;
    int a[n];
    cout<<"Enter array values :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int d;
    cout<<"Enter d value :\n";
    cin>>d;
    radixsort(a, n, d);
    cout<<"\nRadix Sorted Array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    delete []a;
    return 0;
}
*/
