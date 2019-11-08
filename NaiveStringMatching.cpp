#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++) {
		if(s1[i]==s2[0]) {
			int flag = 0;
			for(int j=0;j<s2.size();j++) {
				if(s2[j]!=s1[i+j]) flag = 1;
			}
			if(flag==0) {
				cout<<1<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}