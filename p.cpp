#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string exp;
	char c[100];
	cin.getline(c, 100);
	for(int i=0;c[i]!='\0';i++)
		exp.push_back(c[i]);
	cout<<exp<<endl;
	return 0;
}