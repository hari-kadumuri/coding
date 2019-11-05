#include <iostream>
using namespace std;

void modsort(int* a, int n) {
    int count[3] = {0, 0, 0};
    for(int i=0;i<n;i++)
        count[a[i]]++;
    for(int i=0;i<n;i++) {
        if(count[0]>0) {
            a[i] = 0;
            count[0]--;
        }
        else if(count[1]>0) {
            a[i] = 1;
            count[1]--;
        }
        else
            a[i] = 2;
    }
}

int main() {
	int T;
    cout<<"enter T:";
    cin>>T;
	while(T-- >0) {
	    int p, n;
        cin>>n;
	    int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
	    modsort(a, n);
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}