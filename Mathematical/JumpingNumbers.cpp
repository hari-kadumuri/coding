#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*naive solution that runs in O(n) time is to consider every number upto n and check if it is a jumping number. The following are two efficient ways to find jumping numbers*/


/**************************Following is the code to print Jumping numbers in sorted order. This runs in O(klogk + k) where k is the number of jumping numbers upto n**************************/
/*void bfs(int x, int num, vector<int> &a) {
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(x<=num) {
			//cout<<x<<" ";
			a.push_back(x);
			int last_dig = x%10;
			if(last_dig==0)
				q.push(x*10 + last_dig+1);
			else if (last_dig==9)
				q.push(x*10 + last_dig-1);
			else {
				q.push(x*10 + last_dig+1);
				q.push(x*10 + last_dig-1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		vector<int> a;
		for(int i=0;i<9;i++)
			bfs(i+1, n, a);
		sort(a.begin(), a.end());
		for(int i=0;i<a.size();i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}*/

/**************************Following is the code to print Jumping numbers in unsorted order. This runs in O(k) where k is the number of jumping numbers upto n**************************/
void bfs(int x, int num) {
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(x<=num) {
			cout<<x<<" ";
			int last_dig = x%10;
			if(last_dig==0)
				q.push(x*10 + last_dig+1);
			else if (last_dig==9)
				q.push(x*10 + last_dig-1);
			else {
				q.push(x*10 + last_dig+1);
				q.push(x*10 + last_dig-1);
			}
		}
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		for(int i=0;i<9;i++)
			bfs(i+1, n);
	}
	return 0;
}
