#include<iostream>
using namespace std;

int findmaxcrosssum(int *a, int left, int mid, int right) {
    int sum = 0,pres_sum=0;
    for(int i=mid;i>=left;i--) {
        pres_sum+=a[i];
        if(pres_sum>sum)
            sum = pres_sum;
    }
    int leftsum = sum;
    sum = 0, pres_sum = 0;
    for(int i=mid+1;i<=right;i++) {
        pres_sum+=a[i];
        if(pres_sum>sum)
            sum = pres_sum;
    }
    sum+=leftsum;
    return sum;
}

int findmaxsum(int *a, int left, int right) {
    if(left==right)
        return a[left];
    int mid = (left+right)/2;
    int l = findmaxsum(a, left, mid);
    int r = findmaxsum(a, mid+1, right);
    int c = findmaxcrosssum(a, left, mid, right);
    if(l>r&&l>c)
        return l;
    if(r>l&&r>c)
        return r;
    else
        return c;
}

/*int main() {
    int n,*a;
    cout<<"Enter n value:\n";
    cin>>n;
    a = new int[n];
    cout<<"enter array values :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Max Sub-Array Sum =\t"<<findmaxsum(a,0,n-1);
    delete []a;
    return 0;
}*/
