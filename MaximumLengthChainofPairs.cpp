#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return (a.first<b.first || (a.first==b.first && a.second<b.second));
}

int max(int a, int b) {
	return (a>b?a:b);
}

bool follows(pair<int, int> a, pair<int, int> b) {
	return (a.second<b.first);
}

int getLongestChainofPairs(pair<int, int> pairs[], int n) {
	sort(pairs, pairs+n, compare);
	for(int i=0;i<n;i++)
		cout<<"<"<<pairs[i].first<<", "<<pairs[i].second<<"> ";
	cout<<endl;
	int count[n] = {1};
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(follows(pairs[j], pairs[i]))
				count[i] = max(count[i], 1+count[j]);
		}
	}
	int maxval = 1;
	for(int i=0;i<n;i++)
		maxval = max(maxval, count[i]);
	return maxval;
}

int main(int argc, char const *argv[])
{
	int n;
	n = 5;
	pair<int, int> pairs[n] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
	cout<<getLongestChainofPairs(pairs, n)<<endl;
	return 0;
}