#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a>b?a:b);
}

int maxSubSequence(char* a, char* b, int m, int n) {
    int opt[m+1][n+1];
    for(int i=0;i<=m;i++)
        opt[i][0] = 0;
    for(int i=0;i<=n;i++)
        opt[0][i] = 0;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++)
            opt[i][j] = (a[i-1]==b[j-1]?max(1+opt[i-1][j-1], max(opt[i][j-1], opt[i-1][j])):max(opt[i][j-1], opt[i-1][j]));
    }
    for(int i=0;i<=m;i++) {
    	for(int j=0;j<=n;j++) {
    		cout<<opt[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return opt[m][n];
}

int main() {
	//code
	int T;
	cin>>T;
	while(T-- >0) {
	    int m, n;
	    cin>>m>>n;
	    char a[m], b[n];
	    cin>>a>>b;
	    cout<<maxSubSequence(a, b, m, n)<<endl;
	}
	return 0;
}