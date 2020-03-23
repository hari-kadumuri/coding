#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string tree = "(0(5(6()())(4()(9)))(7(12()())(3()())))";
	// cin>>tree;
	int k;
	cin>>k;
	int prod = 1, depth = -1;
	for(int i=0;i<tree.size();i++) {
		if(tree[i]=='(') {
			depth++;
		}
		else if(tree[i]==')')
			depth--;
		else {
			int sum = 0;
			if(depth!=k)
				continue;
			while(tree[i]>='0' && tree[i]<='9') {
				sum = sum*10+tree[i]-'0';
				i++;
			}
			i--;
			prod *= sum;
		}
	}
	cout<<prod<<endl;
	return 0;
}