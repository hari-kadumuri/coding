#include <iostream>
using namespace std;

void printDuplicates(int* a, int n) {
	int flag = 0;
	cout<<endl;
	for(int i=0;i<n;i++) {
		int idx = a[i]%n;
		a[idx] += n;
		if(a[idx]/n>=2) {
			cout<<a[i]%n<<" ";
			flag = 1;
		}
	}
	if(flag==0)
		cout<<-1;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T-- >0) {
		int n; cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printDuplicates(a, n);
		cout<<endl;
	}
	return 0;
}