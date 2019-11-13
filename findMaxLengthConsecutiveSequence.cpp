#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// incomplete
int findMaxLenConsecutiveSeq(int* a, int n) {
	unordered_map<int, int> s;
	bool visited[n] = {false};
	for(int i=0;i<n;i++)
		s[a[i]] = i+1;
	int maxv = -1;
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			int count = 1, forward = a[i]+1, backward = a[i]-1;
			while(s[forward] != 0) {
				count++;
				forward++;
				visited[s[forward]-1] = true;
			}
			while(s[backward] != 0) {
				count++;
				backward--;
				visited[s[backward]] = true;
			}
			if(count>maxv)
				maxv = count;
		}
	}
	return maxv;
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<findMaxLenConsecutiveSeq(a, n)<<endl;
	return 0;
}