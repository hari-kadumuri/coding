#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n, *a, x, y; cin>>n;
		a = new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cin>>x>>y; bool flagx = false, flagy = false;
		for(int i=0;i<n;i++) {
			if(a[i]==x) {
				x = i;
				flagx = true;
			}
			if(a[i]==y) {
				y = i;
				flagy = true;
			}
		}
		// Printing the output
		if(flagx &&flagy)
			cout<<endl<<y-x<<endl;
		else
			cout<<endl<<-1<<endl;
		delete[] a;
	}
	return 0;
}