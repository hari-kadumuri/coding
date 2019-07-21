#include <iostream>
using namespace std;

long long int findSquaresInMatrix(int m, int n) {
	if(m==1)
		return n;
	if(n==1)
		return m;
	int count = 0, size = 1;
	while(size<=m && size<=n) {
		count += n+1-size;
		size++;
	}
	return count+findSquaresInMatrix(m-1, n);
}

int main(int argc, char const *argv[])
{
	int T, m, n; cin>>T;
	while(T-- >0) {
		cin>>m>>n;
		cout<<findSquaresInMatrix(m, n)<<endl;
	}
	return 0;
}