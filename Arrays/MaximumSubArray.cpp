#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a, x=0; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++, x++)
			if(a[i]>=0)
				break;
		int maxsum = a[x], presentsum = a[x], startidx = x, endidx = x, presentsumstartidx = x;
		for(int i=x+1;i<n;i++) {
			if(a[i]>=0 && a[i-1]>=0)
				presentsum += a[i];
			else if(a[i]>=0 && a[i-1]<0) {
				presentsum = a[i];
				presentsumstartidx = i;
			}
			if(presentsum>maxsum) {
				maxsum = presentsum;
				startidx = presentsumstartidx;
				endidx = i;
			}
		}
		// Printing maximum non-negative subarray
		cout<<endl;
		if(startidx>=n)
			cout<<"There is no non-negative subarray";
		else {
			for(int i=startidx;i<=endidx && i<n;i++)
				cout<<a[i]<<" ";
		}
		cout<<endl;
		delete[] a;
	}
	return 0;
}