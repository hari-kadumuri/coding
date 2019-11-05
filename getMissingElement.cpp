#include <iostream>
using namespace std;

int getLostElement(int* a, int n) {
    int sum = 0;
    for(int i=0;i<n-1;i++)
        sum += a[i];
    cout<<"sum = "<<sum<<endl;
    return n*(n+1)/2 - sum;
}

int main() {
    int T; cin>>T;
	while(T-- >0) {
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<getLostElement(a, n)<<endl;
	}
	return 0;
}