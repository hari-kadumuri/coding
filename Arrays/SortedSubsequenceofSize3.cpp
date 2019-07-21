#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a, y; cin>>n;
		bool flagx = true, flagy = false, flagz = false;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++) {
			if(!flagy) {
				if(a[i]-a[0]!=0 && (y = i))
					flagy = true;
			}
			else
				if(a[i]-a[y]!=0 && a[i]-a[0]!=0 && (flagz = true))
					break;
		}
		// Printing the output
		if(flagx && flagy && flagz)
			cout<<endl<<1<<endl;
		else
			cout<<endl<<0<<endl;
		delete[] a;
	}
	return 0;
}