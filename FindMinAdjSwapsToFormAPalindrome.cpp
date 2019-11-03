#include <iostream>
#include <string>
using namespace  std;

void swap(char* a, char* b) {
	char c = *a;
	*a = *b;
	*b = c;
}

int findFromLast(string s, int idx, int j) {
	int n = s.size();
	for(int i=j-1;i>=0;i--)
		if(s[idx]==s[i])
			return i;
	return -1;
}

int findMinSwaps(string s) {
	int i = 0, j = s.size()-1, count = 0;
	cout<<"n = "<<s.size()<<endl;
	while(i<j) {
		if(s[i]!=s[j]) {
			int k = findFromLast(s, i, j);
			cout<<"k = "<<k<<" at i = "<<i<<endl;
			if(k==-1 || k==i)
				return -1;
			for(int l=k;l<j;l++) {
				swap(&s[l], &s[l+1]);
				count++;
			}
		}
		i++;
		j--;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<"s = "<<s<<endl;
	cout<<findMinSwaps(s)<<endl;
	return 0;
}