#include <iostream>
using namespace std;

int findPivot(int* a, int l, int r) {
    if(l==r)
        return l;
    if(l==r-1)
        return (a[l]>a[r]?l:-1);
    int mid = (l+r)/2;
    if(a[l]>=a[mid])
        return findPivot(a, l, mid);
    return findPivot(a, mid+1, r);
}

int Bsearch(int* a, int l, int r, int k) {
    if(l==r)
        return (a[l]==k?l:-1);
    if(l>r)
        return -1;
    int mid = (l+r)/2;
    if(k<a[l] || k>a[r])
        return -1;
    return (a[mid]>=k?Bsearch(a, l, mid, k):Bsearch(a, mid+1, r, k));
}

int findElement(int* a, int n, int k) {
    int pivot = findPivot(a, 0, n-1);
    if(pivot<0) {
        return Bsearch(a, 0, n-1, k);
    }
    int x = Bsearch(a, 0, pivot, k);
    int y = Bsearch(a, pivot+1, n-1, k);
    return (x>y?x:y);
}

int main() {
	//code
	int T;
	cin>>T;
	while(T-- >0) {
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int k; cin>>k;
	    cout<<findElement(a, n, k)<<endl;
	}
	return 0;
}