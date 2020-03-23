#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	int count1[256] = {0}, count2[256] = {0};
	cin>>str1>>str2;
	for(auto x: str1)
		count1[x]++;
	for(auto x: str2)
		count2[x]++;
	bool flag = true;
	for(int i=0;i<256;i++)
		if(count1[i]>count2[i])
			flag = false;
	cout<<(flag?"yes":"no")<<endl;
	return 0;
}